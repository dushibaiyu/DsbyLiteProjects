#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnbutClink()));
    connect(ui->Post,SIGNAL(clicked()),this,SLOT(OnPostClink()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnbutClink()
{
    qDebug()<< "Onbutclink()  " <<  this->ui->lineEdit->text();

    QNetworkRequest header(this->ui->lineEdit->text());
    reply =  manager.get(header);
    connect(reply,&QNetworkReply::finished,this,&MainWindow::Settext);
}

void MainWindow::Settext()
{

    this->ui->textEdit->setText(reply->readAll());
    reply->deleteLater();
    reply = nullptr;
}

void MainWindow::OnPostClink()
{
    QNetworkRequest header(this->ui->lineEdit->text());
    QByteArray BArry;
    BArry.append(this->ui->postData->toPlainText());
    reply =  manager.post(header,BArry);
    qDebug() << "Post data :" << BArry;
    //post数据没有截取到。
    connect(reply,&QNetworkReply::finished,this,&MainWindow::Settext);
}
