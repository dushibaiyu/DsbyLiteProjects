#include "setlitedb.h"
#include "ui_setlitedb.h"

setLiteDb::setLiteDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setLiteDb)
{
    ui->setupUi(this);
    db = dbClass::getDbClass();

    ui->server->setText(db->getServer());
    ui->port->setText(db->getPort());
    ui->username->setText(db->getUsername());
    ui->password->setText(db->getPassword());
    ui->dbname->setText(db->getDbname());

    test = QSqlDatabase::addDatabase("QPSQL","test");
    connect(ui->ok,SIGNAL(clicked()),this,SLOT(setDb()));
    connect(ui->exit,SIGNAL(clicked()),this,SLOT(close()));
    connect(ui->test,SIGNAL(clicked()),this,SLOT(testDb()));
}

setLiteDb::~setLiteDb()
{
    delete ui;
}

void setLiteDb::setDb()
{
    db->setServer(ui->server->text());
    db->setPort(ui->port->text());
    db->setUsername(ui->username->text());
    db->setPassword(ui->password->text());
    db->setDbname(ui->dbname->text());
    db->upDb();
    this->close();
}

void setLiteDb::testDb()
{
    test.setHostName(ui->server->text());
    test.setPort(ui->port->text().toInt());
    test.setUserName(ui->username->text());
    test.setPassword(ui->password->text());
    test.setDatabaseName(ui->dbname->text());

    if(test.open())
    {
        QMessageBox mbox;
        mbox.setText("连接成功，请保存配置！");
        mbox.exec();
        test.close();
    }
    else
    {
        QMessageBox mbox;
        mbox.setText("连接失败，请检查您的设置！");
        mbox.exec();
    }

}
