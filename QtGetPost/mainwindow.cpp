#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnbutClink()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(butclink()));
    connect(&http,SIGNAL(GetBack(QString)),this,SLOT(Settext(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::OnbutClink()
{
    qDebug()<< "Onbutclink()  " <<  this->ui->lineEdit->text();
    HttpGet http1(this->ui->lineEdit->text());
    this->ui->textEdit->setText(http1.httpGet());
}

void MainWindow::Settext(const QString &text)
{
    qDebug()<< "Settext() ";
    this->ui->textEdit->setText(text);
}

void MainWindow::butclink()
{
    qDebug()<< "butclink() " <<  this->ui->lineEdit->text();
    http.setUrl(this->ui->lineEdit->text());
    http.startGet();
}
