#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPainter>
#include <QTime>
#include <QDebug>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objm.setFeature2D(cv::xfeatures2d::SURF::create(2000));
    objm.setMatcher(new cv::FlannBasedMatcher);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushLogo_clicked()
{
   /* QString*/ path2 = QFileDialog::getOpenFileName(this,tr("打开Logo文件"),QString(),"image file (*.jpg *.png *.jpeg)");
    if (path2.isEmpty()) return;
    QImage img;
    img.load(path2);
    this->ui->logo->setPixmap(QPixmap::fromImage(img.scaled(150,150)));
    cv::Mat mat = cv::imread(path2.toLocal8Bit().data()/*,CV_LOAD_IMAGE_GRAYSCALE*/);
    objm.restObjMat(mat);
}

void MainWindow::on_pushimg_clicked()
{
    path = QFileDialog::getOpenFileName(this,tr("打开Logo文件"),QString(),"image file (*.jpg *.png *.jpeg)");
    if (path.isEmpty()) return;
    image.load(path);
    this->ui->image->setPixmap(QPixmap::fromImage(image.scaled(450,450)));
}

//dst_cvsize.width = src->width * scale;		//目标图像的宽为源图象宽的scale倍
//    dst_cvsize.height = src->height * scale;	//目标图像的高为源图象高的scale倍

//    dst = cvCreateImage( dst_cvsize, src->depth, src->nChannels);	//构造目标图象
//    cvResize(src, dst, CV_INTER_LINEAR);	//缩放源图像到目标图像

void MainWindow::on_pushCheck_clicked()
{
    cv::Mat mat = cv::imread(path.toLocal8Bit().data()/*,CV_LOAD_IMAGE_GRAYSCALE*/);
    cv::Mat img_matches;
    QTime tm;
    tm.start();//大图片崩溃
//    cv::Mat mat2 = cv::imread(path2.toLocal8Bit().data(),CV_LOAD_IMAGE_GRAYSCALE);
//    ObjectMat objm(mat2,cv::xfeatures2d::SIFT::create(),new cv::FlannBasedMatcher);
    std::vector<cv::Point2f>  pont;
    objm.matchToPoint(mat,pont,&img_matches);
    qDebug() << " get point :" << tm.elapsed();
    QPainter pain(&image);
    QPen pen(Qt::SolidLine);
    pen.setColor(QColor(Qt::red));
    pen.setWidth(3);
    pain.setPen(pen);
    pain.drawLine(QPointF(pont[0].x,pont[0].y),QPointF(pont[1].x,pont[1].y));
    pain.drawLine(QPointF(pont[1].x,pont[1].y),QPointF(pont[2].x,pont[2].y));
    pain.drawLine(QPointF(pont[2].x,pont[2].y),QPointF(pont[3].x,pont[3].y));
    pain.drawLine(QPointF(pont[3].x,pont[3].y),QPointF(pont[0].x,pont[0].y));
    pain.end();
    this->ui->image->setPixmap(QPixmap::fromImage(image.scaled(450,450)));
    cv::imshow( "Good Matches & Object detection", img_matches );

}
