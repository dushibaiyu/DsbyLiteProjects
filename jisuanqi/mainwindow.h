#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //处理数字和按键
    void b0();
    void b1();
    void b2();
    void bDot();
    void b3();
    void b4();
    void b5();
    void b6();
    void b7();
    void b8();
    void b9();

    //处理计算操作
    void cAdd();
    void cBspace();
    void cClean();
    void cCos();
    void cCosh();
    void cSin();
    void cSinh();
    void cTan();
    void cTanh();
    void cDivide();
    void c1x();
    void cEquel();
    void cN1();
    void cMinus();
    void cMultiply();
    void cPow();
    void cSpr();
    
private:
    QString a,b,tshow;
    char ch;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
