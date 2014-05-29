#include "singin.h"
#include "ui_singin.h"

singin::singin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::singin)
{
    ui->setupUi(this);
    litedb = dbClass::getDbClass();
    mainwindow = new MainWindow;
    connect(ui->Singin,SIGNAL(clicked()),this,SLOT(Singin()));
    connect(ui->Exit,SIGNAL(clicked()),this,SLOT(close()));

}

singin::~singin()
{
    delete ui;
    delete mainwindow;
}

void singin::Singin()
{
    QString tep = ui->lineEdit->text();
    qDebug() << "password" << tep;
    qDebug()<< "db password" << litedb->getCheck();
    if (tep != litedb->getCheck())
    {
        QMessageBox tmp;
        tmp.setText("密码错误！请重新输入");
        tmp.exec();
    }
    else
    {
        this->hide();
        mainwindow->show();
        this->close();
    }
}

