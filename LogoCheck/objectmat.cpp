#include "objectmat.h"
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <QDebug>

using namespace std;
using namespace cv;

ObjectMat::ObjectMat(cv::Mat & obj,cv::Ptr<cv::Feature2D> detector, cv::Ptr<cv::DescriptorMatcher> matcher) :
    detector_(detector),matcher_(matcher),ransacReprojThreshold(3),isDoubleCheck(false),kun(1)
{
    restObjMat(obj);
}

void ObjectMat::initObjImg()
{
    if (detector_.empty()) return;
    detector_->detect(object_img,points_obj);
    detector_->compute(object_img,points_obj,descriptors_obj);
}

int ObjectMat::matchToPoint(cv::Mat & scene, std::vector<Point2f> &outPoint, cv::Mat * img_matches)
{
    if (scene.empty() || object_img.empty() || detector_.empty() || matcher_.empty())
        return -1;
    outPoint.clear();
    outPoint.reserve(4);
    std::vector<cv::KeyPoint> points_scen;
    cv::Mat descriptors_scen;
    detector_->detect(scene,points_scen);
    detector_->compute(scene,points_scen,descriptors_scen);

    std::vector<cv::DMatch> matches;
    if (isDoubleCheck) {
        crossCheckMatching(descriptors_scen,matches,kun);
    } else {
        matcher_->match(descriptors_obj,descriptors_scen,matches);
    }
    vector<int> queryIdxs( matches.size() ), trainIdxs( matches.size() );
    for( size_t i = 0; i < matches.size(); i++ ) {
        queryIdxs[i] = matches[i].queryIdx;
        trainIdxs[i] = matches[i].trainIdx;
    }

    vector<Point2f> points1; KeyPoint::convert(points_obj, points1, queryIdxs);
    vector<Point2f> points2; KeyPoint::convert(points_scen, points2, trainIdxs);
    Mat H12 = findHomography( Mat(points1), Mat(points2), CV_RANSAC,ransacReprojThreshold);

    if (!H12.empty()) {
        Mat points1t;
        vector<char> matchesMask( matches.size(), 0 );
        std::vector<cv::Point2f> obj_corners(4);
        obj_corners[0] = cv::Point2f(0,0);
        obj_corners[1] = cv::Point2f(object_img.cols,0);
        obj_corners[2] = cv::Point2f( object_img.cols, object_img.rows);
        obj_corners[3] = cv::Point2f(0,object_img.rows);

        perspectiveTransform(obj_corners, outPoint, H12);
        perspectiveTransform(Mat(points1), points1t, H12);
        int pint = 0;
        for( size_t i1 = 0; i1 < points1.size(); i1++ )
        {
            if( norm(points2[i1] - points1t.at<Point2f>((int)i1,0)) <= ransacReprojThreshold ) {
                matchesMask[i1] = 1;
                ++ pint;
            }
        }

        if (img_matches) {
            drawMatches( object_img, points_obj, scene, points_scen,
                         matches, *img_matches, Scalar::all(-1), Scalar::all(-1),
                         matchesMask/*, DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS*/ );
            cv::Scalar scalar(0, 255, 0);
            cv::line( *img_matches, outPoint[0] + obj_corners[1], outPoint[1] + obj_corners[1], scalar, 3 );
            cv::line( *img_matches, outPoint[1] + obj_corners[1], outPoint[2] + obj_corners[1], scalar, 3 );
            cv::line( *img_matches, outPoint[2] + obj_corners[1], outPoint[3] + obj_corners[1], scalar, 3 );
            cv::line( *img_matches, outPoint[3] + obj_corners[1], outPoint[0] + obj_corners[1], scalar, 3 );
        }

        return pint;

    } else {
        if (img_matches) {
            drawMatches( object_img, points_obj, scene, points_scen,
                         matches, *img_matches, Scalar::all(-1), Scalar::all(-1),
                         vector<char>()/*, DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS */);
        }

    }

    return 0;

}

void ObjectMat::crossCheckMatching(const cv::Mat& descriptors, std::vector<cv::DMatch>& matches2, int knn)
{
    std::vector<std::vector<cv::DMatch> > matches12, matches21;
    matcher_->knnMatch( descriptors_obj, descriptors, matches12, knn );
    matcher_->knnMatch( descriptors, descriptors_obj, matches21, knn );
    for( size_t m = 0; m < matches12.size(); m++ )
    {
        bool findCrossCheck = false;
        for( size_t fk = 0; fk < matches12[m].size(); fk++ )
        {
            cv::DMatch forward = matches12[m][fk];

            for( size_t bk = 0; bk < matches21[forward.trainIdx].size(); bk++ )
            {
                cv::DMatch backward = matches21[forward.trainIdx][bk];
                if( backward.trainIdx == forward.queryIdx )
                {
                    matches2.push_back(forward);
                    findCrossCheck = true;
                    break;
                }
            }
            if( findCrossCheck ) break;
        }
    }
}
