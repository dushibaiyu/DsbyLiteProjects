#ifndef OBJECTMAT_H
#define OBJECTMAT_H

#include <opencv2/core.hpp>
#include <opencv2/features2d.hpp>

class ObjectMat
{
public:
    ObjectMat(cv::Mat & obj = cv::Mat(),cv::Ptr<cv::Feature2D> detector = cv::Ptr<cv::Feature2D>(),
              cv::Ptr<cv::DescriptorMatcher> matcher = cv::Ptr<cv::DescriptorMatcher>());
    ~ObjectMat(){}

    inline void setFeature2D(cv::Ptr<cv::Feature2D> detector) {detector_ = detector;initObjImg();}

    inline void setMatcher(cv::Ptr<cv::DescriptorMatcher> matcher){matcher_ = matcher;}

    inline cv::Ptr<cv::Feature2D> getFeature2D () const {return detector_;}

    inline cv::Ptr<cv::DescriptorMatcher> getMatcher () const {return matcher_;}

    inline cv::Mat getObjMat() const {return object_img;}

    inline void restObjMat(cv::Mat & obj) {
        if (obj.empty()) return;
        object_img = obj;
        initObjImg();
    }

    inline void  setDoubleCheck(bool isdouble,int kun = 1) {
        isDoubleCheck = isdouble;
        if (isDoubleCheck) this->kun = kun;
    }

    inline bool getDoubleCheck() const {return isDoubleCheck;}
    inline int getdoubleKun () const {return kun;}

    inline int getRansacReprojThreshold() const {return ransacReprojThreshold;}
    inline void setRansacReprojThreshold(int hold) {ransacReprojThreshold = hold;}

    int matchToPoint(cv::Mat & scene,std::vector<cv::Point2f> & outPoint,cv::Mat * img_matches = nullptr);
protected:
    void initObjImg();
    void crossCheckMatching(const cv::Mat& descriptors,std::vector<cv::DMatch>& matches12, int knn = 1);
private:
    cv::Ptr<cv::Feature2D>  detector_;
    cv::Ptr<cv::DescriptorMatcher> matcher_;

    cv::Mat object_img;
    std::vector<cv::KeyPoint> points_obj;
    cv::Mat descriptors_obj;
    int ransacReprojThreshold;

    bool isDoubleCheck;
    int kun;
};

#endif // OBJECTMAT_H
