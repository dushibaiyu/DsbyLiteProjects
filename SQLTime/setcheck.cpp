#include "setcheck.h"
#include "ui_setcheck.h"
#include "dbclass.h"
#include <QMessageBox>

setcheck::setcheck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setcheck)
{
    ui->setupUi(this);
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(okButton()));
    connect(ui->no,SIGNAL(clicked()),this,SLOT(close()));
}

setcheck::~setcheck()
{
    delete ui;
}

void setcheck::okButton()
{
    dbClass * db = dbClass::getDbClass();
    db->SetCheck(ui->lineEdit->text());
    db->upDb();
    QMessageBox mbox;
    mbox.setText("密码修改成功，请牢记您的密码！");
    mbox.exec();
    this->close();
}

