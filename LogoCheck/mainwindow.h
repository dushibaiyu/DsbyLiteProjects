#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include "objectmat.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushLogo_clicked();

    void on_pushimg_clicked();

    void on_pushCheck_clicked();

private:
    Ui::MainWindow *ui;
    QImage image;
    QString path,path2;
    ObjectMat objm;
};

#endif // MAINWINDOW_H
