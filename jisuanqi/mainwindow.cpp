#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()& ~Qt::WindowMaximizeButtonHint);
    setFixedSize(this->width(), this->height());
    ui->numShow->setText("0");
    a="0"; b="0"; ch = ' '; tshow.clear();//初始化变量

    //链接数字按钮的响应
    QObject::connect(ui->b0, SIGNAL(clicked()), this, SLOT(b0()));
    QObject::connect(ui->b2, SIGNAL(clicked()), this, SLOT(b2()));
    QObject::connect(ui->b3, SIGNAL(clicked()), this, SLOT(b3()));
    QObject::connect(ui->b1, SIGNAL(clicked()), this, SLOT(b1()));
    QObject::connect(ui->b4, SIGNAL(clicked()), this, SLOT(b4()));
    QObject::connect(ui->b5, SIGNAL(clicked()), this, SLOT(b5()));
    QObject::connect(ui->b6, SIGNAL(clicked()), this, SLOT(b6()));
    QObject::connect(ui->b7, SIGNAL(clicked()), this, SLOT(b7()));
    QObject::connect(ui->b8, SIGNAL(clicked()), this, SLOT(b8()));
    QObject::connect(ui->b9, SIGNAL(clicked()), this, SLOT(b9()));
    QObject::connect(ui->bDot, SIGNAL(clicked()), this, SLOT(bDot()));

    //链接运算符号的按钮响应
    QObject::connect(ui->cMinus,SIGNAL(clicked()), this, SLOT(cMinus()));
    QObject::connect(ui->cAdd,SIGNAL(clicked()), this, SLOT(cAdd()));
    QObject::connect(ui->cBspace,SIGNAL(clicked()), this, SLOT(cBspace()));
    QObject::connect(ui->cClean,SIGNAL(clicked()), this, SLOT(cClean()));
    QObject::connect(ui->cCos,SIGNAL(clicked()), this, SLOT(cCos()));
    QObject::connect(ui->cCosh,SIGNAL(clicked()), this, SLOT(cCosh()));
    QObject::connect(ui->cSin,SIGNAL(clicked()), this, SLOT(cSin()));
    QObject::connect(ui->cSinh,SIGNAL(clicked()), this, SLOT(cSinh()));
    QObject::connect(ui->cTan,SIGNAL(clicked()), this, SLOT(cTan()));
    QObject::connect(ui->cTanh,SIGNAL(clicked()), this, SLOT(cTanh()));
    QObject::connect(ui->cDivide,SIGNAL(clicked()), this, SLOT(cDivide()));
    QObject::connect(ui->c1x,SIGNAL(clicked()), this, SLOT(c1x()));
    QObject::connect(ui->cN1,SIGNAL(clicked()), this, SLOT(cN1()));
    QObject::connect(ui->cMultiply,SIGNAL(clicked()), this, SLOT(cMultiply()));
    QObject::connect(ui->cPow,SIGNAL(clicked()), this, SLOT(cPow()));
    QObject::connect(ui->cSpr,SIGNAL(clicked()), this, SLOT(cSpr()));
    QObject::connect(ui->cEquel,SIGNAL(clicked()), this, SLOT(cEquel()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//处理数字按键
void MainWindow::b0()
{
    if (b != "0")
    {
        b.append('0');
        ui->numShow->setText(b);
    }
}

void MainWindow::b1()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('1');
        ui->numShow->setText(b);
    }
    else
    {
        b = "1";
        ui->numShow->setText(b);
    }

}

void MainWindow::b2()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('2');
        ui->numShow->setText(b);
    }
    else
    {
        b = "2";
        ui->numShow->setText(b);
    }
}

void MainWindow::bDot()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('.');
        ui->numShow->setText(b);
    }
    else
    {
        b = "0.";
        ui->numShow->setText(b);
    }
}

void MainWindow::b3()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('3');
        ui->numShow->setText(b);
    }
    else
    {
        b = "3";
        ui->numShow->setText(b);
    }
}

void MainWindow::b4()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('4');
        ui->numShow->setText(b);
    }
    else
    {
        b = "4";
        ui->numShow->setText(b);
    }
}

void MainWindow::b5()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('5');
        ui->numShow->setText(b);
    }
    else
    {
        b = "5";
        ui->numShow->setText(b);
    }
}

void MainWindow::b6()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('6');
        ui->numShow->setText(b);
    }
    else
    {
        b = "6";
        ui->numShow->setText(b);
    }
}

void MainWindow::b7()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('7');
        ui->numShow->setText(b);
    }
    else
    {
        b = "7";
        ui->numShow->setText(b);
    }
}

void MainWindow::b8()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('8');
        ui->numShow->setText(b);
    }
    else
    {
        b = "8";
        ui->numShow->setText(b);
    }
}

void MainWindow::b9()
{
    if (b != "0")
    {
        b = ui->numShow->text();
        b.append('9');
        ui->numShow->setText(b);
    }
    else
    {
        b = "9";
        ui->numShow->setText(b);
    }
}

//处理计算操作
void MainWindow::cAdd()
{
    if (ch == ' ')
    {
        a = b;
    }
    else
    {
        double ad = a.toDouble(),bd = b.toDouble(),cd;
        switch(ch)
        {
        case '+' :
           cd = ad + bd;
           a = QString::number(cd,'f',6);
           break;
        case '-' :
           cd = ad - bd;
           a = QString::number(cd,'f',6);
            break;
        case '*' :
           cd = ad * bd;
           a = QString::number(cd,'f',6);
           break;
        case '/' :
           cd = ad / bd;
           a = QString::number(cd,'f',6);
           break;
        case '^' :
           cd = pow(ad, bd);
           a = QString::number(cd,'f',6);
           break;
        }
    }
    b = "0";
    ch = '+';
    tshow = a;
    tshow.append('+');
    ui->textShow->setText(tshow);
}

void MainWindow::cBspace()
{
    ui->numShow->backspace();
    b = ui->numShow->text();
    if (b.isEmpty())
    {
        b = "0";
        ui->numShow->setText(b);
    }
}

void MainWindow::cClean()
{
    a = "0";
    b = "0";
    tshow.clear();
    ch = ' ';
    ui->textShow->setText(tshow);
    ui->numShow->setText("0");
}

void MainWindow::cCos()
{

    QString temp = ui->numShow->text();
    b = temp;
    double bd = b.toDouble();
    bd = cos(bd);
    b = QString::number(bd,'f',6);
    tshow = tshow+"cos(" + temp + ")";
    ui->textShow->setText(tshow);
    ui->numShow->setText(b);
}

void MainWindow::cCosh()
{
    QString temp = ui->numShow->text();
    b = temp;
    double bd = b.toDouble();
    bd = cosh(bd);
    b = QString::number(bd,'f',6);
    tshow = tshow+"cosh(" +temp + ")";
    ui->textShow->setText(tshow);
    ui->numShow->setText(b);
}

void MainWindow::cSin()
{
    QString temp = ui->numShow->text();
    b = temp;
    double bd = b.toDouble();
    bd = sin(bd);
    b = QString::number(bd,'f',6);
    tshow = tshow+"sin(" + temp + ")";
    ui->textShow->setText(tshow);
    ui->numShow->setText(b);

}

void MainWindow::cSinh()
{
    QString temp = ui->numShow->text();
    b = temp;
    double bd = b.toDouble();
    bd = sinh(bd);
    b = QString::number(bd,'f',6);
    tshow = tshow+"sinh(" + temp + ")";
    ui->textShow->setText(tshow);
    ui->numShow->setText(b);
}

void MainWindow::cTan()
{
    QString temp = ui->numShow->text();
    b = temp;
    double bd = b.toDouble();
    bd = tan(bd);
    b = QString::number(bd,'f',6);
    tshow = tshow+"tan(" + temp + ")";
    ui->textShow->setText(tshow);
    ui->numShow->setText(b);
}

void MainWindow::cTanh()
{
    QString temp = ui->numShow->text();
    b = temp;
    double bd = b.toDouble();
    bd = tanh(bd);
    b = QString::number(bd,'f',6);
    tshow = tshow+"tanh(" + temp + ")";
    ui->textShow->setText(tshow);
    ui->numShow->setText(b);
}

void MainWindow::cDivide()//除
{    
    if (ch == ' ')
    {
        a = b;
    }
    else
    {
        double ad = a.toDouble(),bd = b.toDouble(),cd;
        switch(ch)
        {
            case '+' :
               cd = ad + bd;
               a = QString::number(cd,'f',6);
               break;
            case '-' :
               cd = ad - bd;
               a = QString::number(cd,'f',6);
                break;
            case '*' :
               cd = ad * bd;
               a = QString::number(cd,'f',6);
               break;
            case '/' :
               cd = ad / bd;
               a = QString::number(cd,'f',6);
               break;
            case '^' :
               cd = pow(ad, bd);
               a = QString::number(cd,'f',6);
               break;
        }
    }
    b = "0";
    ch = '/';
    tshow = a;
    tshow.append('/');
    ui->textShow->setText(tshow);
}

void MainWindow::c1x()
{
    b = ui->numShow->text();
    if (b != "0")
    {
        QString temp = b;
        double bd = b.toDouble();
        bd = 1.0/bd;
        b = QString::number(bd,'f',6);
        tshow = tshow+"1/" + temp;
        ui->textShow->setText(tshow);
        ui->numShow->setText(b);
    }
}

void MainWindow::cEquel()//等于
{
    if (ch == ' ')
    {
        a = b;
    }
    else
    {
        double ad = a.toDouble(),bd = b.toDouble(),cd;
        switch(ch)
        {
            case '+' :
               cd = ad + bd;
               a = QString::number(cd,'f',6);
               break;
            case '-' :
               cd = ad - bd;
               a = QString::number(cd,'f',6);
                break;
            case '*' :
               cd = ad * bd;
               a = QString::number(cd,'f',6);
               break;
            case '/' :
               if (bd != 0.0)
               {
                   cd = ad / bd;
                   a = QString::number(cd,'f',6);
               }
               break;
            case '^' :
               cd = pow(ad, bd);
               a = QString::number(cd,'f',6);
               break;
        }
    }
    ch = ' ';
    tshow.clear();
    ui->textShow->setText(tshow);
    ui->numShow->setText(a);
    b = ui->numShow->text();
}

void MainWindow::cN1()
{
    b = ui->numShow->text();
    if (b != "0")
    {
        QString temp = b;
        long int bi= b.toLong();
        for (int i = bi-1; i>=1; --i)
        {
            bi = bi*i;
        }

        b = QString::number(bi);
        tshow = tshow+temp + "!";
        ui->textShow->setText(tshow);
        ui->numShow->setText(b);
    }
}

void MainWindow::cMinus()//减
{
    if (ch == ' ')
    {
        a = b;
    }
    else
    {
        double ad = a.toDouble(),bd = b.toDouble(),cd;
        switch(ch)
        {
            case '+' :
               cd = ad + bd;
               a = QString::number(cd,'f',6);
               break;
            case '-' :
               cd = ad - bd;
               a = QString::number(cd,'f',6);
                break;
            case '*' :
               cd = ad * bd;
               a = QString::number(cd,'f',6);
               break;
            case '/' :
               cd = ad / bd;
               a = QString::number(cd,'f',6);
               break;
            case '^' :
               cd = pow(ad, bd);
               a = QString::number(cd,'f',6);
               break;
        }
    }
    b = "0";
    ch = '-';
    tshow = a;
    tshow.append('-');
    ui->textShow->setText(tshow);
}

void MainWindow::cMultiply()//乘
{
    if (ch == ' ')
    {
        a = b;
    }
    else
    {
        double ad = a.toDouble(),bd = b.toDouble(),cd;
        switch(ch)
        {
            case '+' :
               cd = ad + bd;
               a = QString::number(cd,'f',6);
               break;
            case '-' :
               cd = ad - bd;
               a = QString::number(cd,'f',6);
                break;
            case '*' :
               cd = ad * bd;
               a = QString::number(cd,'f',6);
               break;
            case '/' :
               cd = ad / bd;
               a = QString::number(cd,'f',6);
               break;
            case '^' :
               cd = pow(ad, bd);
               a = QString::number(cd,'f',6);
               break;
        }
    }
    b = "0";
    ch = '*';
    tshow = a;
    tshow.append('*');
    ui->textShow->setText(tshow);
}

void MainWindow::cPow()//幂
{
    if (ch == ' ')
    {
        a = b;
    }
    else
    {
        double ad = a.toDouble(),bd = b.toDouble(),cd;
        switch(ch)
        {
            case '+' :
               cd = ad + bd;
               a = QString::number(cd,'f',6);
               break;
            case '-' :
               cd = ad - bd;
               a = QString::number(cd,'f',6);
                break;
            case '*' :
               cd = ad * bd;
               a = QString::number(cd,'f',6);
               break;
            case '/' :
               cd = ad / bd;
               a = QString::number(cd,'f',6);
               break;
            case '^' :
               cd = pow(ad, bd);
               a = QString::number(cd,'f',6);
               break;
        }
    }
    b = "0";
    ch = '^';
    tshow = a;
    tshow.append('^');
    ui->textShow->setText(tshow);
}

void MainWindow::cSpr()
{
    b = ui->numShow->text();
    if (b != "0")
    {
        QString temp = b;
        double bd = b.toDouble();
        bd = sqrt(bd);
        b = QString::number(bd,'f',6);
        tshow = tshow+"sqrt(" + temp + ")";
        ui->textShow->setText(tshow);
        ui->numShow->setText(b);
    }
}


