#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "setcheck.h"
#include "setlitedb.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //禁止最大化
    this->setWindowFlags(/*Qt::Dialog |*/ Qt::WindowMinimizeButtonHint|Qt::WindowCloseButtonHint);
    litedb = dbClass::getDbClass();
    db = QSqlDatabase::addDatabase("QPSQL","db");
    openDb();
    connect(ui->upTime,SIGNAL(clicked()),this,SLOT(SetTime()));
    connect(ui->dbset, SIGNAL(clicked()),this,SLOT(setDb()));
    connect(ui->loginSet,SIGNAL(clicked()),this,SLOT(setCheck()));
}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::openDb()
{
    db.setHostName(litedb->getServer());
    db.setPort(litedb->getPort().toInt());
    db.setUserName(litedb->getUsername());
    db.setPassword(litedb->getPassword());
    db.setDatabaseName(litedb->getDbname());
    ok = db.open();
    qDebug()<< "mianwindiw：：ok :" << ok;
    if (ok)
    {
        qDebug()<< "exe : upTime()";
        upTime();
        ui->erro->setText("");
    }
    else
    {
        ui->erro->setText("数据库连接失败，请点击右边“数据库设置”设置数据库！");
    }
}

void MainWindow::upTime()
{
    QSqlQuery tmp(db);
    bool isok =  tmp.exec("select start_time,end_time,site,no from m_time_table");
    qDebug()<<"select time:" << isok;
    while(tmp.next())
    {
        if (tmp.value("site").toString() == "总厂")
        {
            if (tmp.value("no").toString() == "1")
            {
                ui->zc1start->setTime(tmp.value("start_time").toTime());
                ui->zc1end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "2")
            {
                ui->zc2start->setTime(tmp.value("start_time").toTime());
                ui->zc2end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "3")
            {
                ui->zc3start->setTime(tmp.value("start_time").toTime());
                ui->zc3end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "4")
            {
                ui->zc4start->setTime(tmp.value("start_time").toTime());
                ui->zc4end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "5")
            {
                ui->zc5start->setTime(tmp.value("start_time").toTime());
                ui->zc5end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "6")
            {
                ui->zc6start->setTime(tmp.value("start_time").toTime());
                ui->zc6end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "7")
            {
                ui->zc7start->setTime(tmp.value("start_time").toTime());
                ui->zc7end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "8")
            {
                ui->zc8start->setTime(tmp.value("start_time").toTime());
                ui->zc8end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "9")
            {
                ui->zc9start->setTime(tmp.value("start_time").toTime());
                ui->zc9end->setTime(tmp.value("end_time").toTime());
                continue;
            }
        }
        else if (tmp.value("site").toString() == "福山")
        {
            if (tmp.value("no").toString() == "1")
            {
                ui->fs1start->setTime(tmp.value("start_time").toTime());
                ui->fs1end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "2")
            {
                ui->fs2start->setTime(tmp.value("start_time").toTime());
                ui->fs2end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "3")
            {
                ui->fs3start->setTime(tmp.value("start_time").toTime());
                ui->fs3end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "4")
            {
                ui->fs4start->setTime(tmp.value("start_time").toTime());
                ui->fs4end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "5")
            {
                ui->fs5start->setTime(tmp.value("start_time").toTime());
                ui->fs5end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "6")
            {
                ui->fs6start->setTime(tmp.value("start_time").toTime());
                ui->fs6end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "7")
            {
                ui->fs7start->setTime(tmp.value("start_time").toTime());
                ui->fs7end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "8")
            {
                ui->fs8start->setTime(tmp.value("start_time").toTime());
                ui->fs8end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "9")
            {
                ui->fs9start->setTime(tmp.value("start_time").toTime());
                ui->fs9end->setTime(tmp.value("end_time").toTime());
                continue;
            }
        }
        else if (tmp.value("site").toString() == "即墨")
        {
            if (tmp.value("no").toString() == "1")
            {
                ui->jm1start->setTime(tmp.value("start_time").toTime());
                ui->jm1end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "2")
            {
                ui->jm2start->setTime(tmp.value("start_time").toTime());
                ui->jm2end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "3")
            {
                ui->jm3start->setTime(tmp.value("start_time").toTime());
                ui->jm3end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "4")
            {
                ui->jm4start->setTime(tmp.value("start_time").toTime());
                ui->jm4end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "5")
            {
                ui->jm5start->setTime(tmp.value("start_time").toTime());
                ui->jm5end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "6")
            {
                ui->jm6start->setTime(tmp.value("start_time").toTime());
                ui->jm6end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "7")
            {
                ui->jm7start->setTime(tmp.value("start_time").toTime());
                ui->jm7end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "8")
            {
                ui->jm8start->setTime(tmp.value("start_time").toTime());
                ui->jm8end->setTime(tmp.value("end_time").toTime());
                continue;
            }
            if (tmp.value("no").toString() == "9")
            {
                ui->jm9start->setTime(tmp.value("start_time").toTime());
                ui->jm9end->setTime(tmp.value("end_time").toTime());
                continue;
            }
        }
    }
}

void MainWindow::SetTime()
{
    QMessageBox tep;
    if (!ok)
    {
         tep.setText("请先设置数据库！");
         tep.exec();
         return ;
    }

    QSqlQuery tmp(db);
    QString sql;

    sql = "update m_time_table set start_time= '";
    sql = sql + ui->zc1start->text() + "', end_time= '" + ui->zc1end->text();
    sql = sql + "' where site='总厂' and no='1'";
    bool temp = tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time= '";
    sql = sql + ui->zc2start->text() + "', end_time= '" + ui->zc2end->text();
    sql = sql + "' where site='总厂' and no='2'";
    temp = tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time= '";
    sql = sql + ui->zc3start->text() + "', end_time= '" + ui->zc3end->text();
    sql = sql + "' where site='总厂' and no='3'";
    temp = tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->zc4start->text() + "', end_time='" + ui->zc4end->text();
    sql = sql + "' where site='总厂' and no='4'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->zc5start->text() + "', end_time='" + ui->zc5end->text();
    sql = sql + "' where site='总厂' and no='5'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->zc6start->text() + "', end_time='" + ui->zc6end->text();
    sql = sql + "' where site='总厂' and no='6'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->zc7start->text() + "', end_time='" + ui->zc7end->text();
    sql = sql + "' where site='总厂' and no='7'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->zc8start->text() + "', end_time='" + ui->zc8end->text();
    sql = sql + "' where site='总厂' and no='8'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->zc9start->text() + "', end_time='" + ui->zc9end->text();
    sql = sql + "' where site='总厂' and no='9'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;


    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs1start->text() + "', end_time='" + ui->fs1end->text();
    sql = sql + "' where site='福山' and no='1'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs2start->text() + "', end_time='" + ui->fs2end->text();
    sql = sql + "' where site='福山' and no='2'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs3start->text() + "', end_time='" + ui->fs3end->text();
    sql = sql + "' where site='福山' and no='3'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs4start->text() + "', end_time='" + ui->fs4end->text();
    sql = sql + "' where site='福山' and no='4'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs5start->text() + "', end_time='" + ui->fs5end->text();
    sql = sql + "' where site='福山' and no='5'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs6start->text() + "', end_time='" + ui->fs6end->text();
    sql = sql + "' where site='福山' and no='6'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs7start->text() + "', end_time='" + ui->fs7end->text();
    sql = sql + "' where site='福山' and no='7'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs8start->text() + "', end_time='" + ui->fs8end->text();
    sql = sql + "' where site='福山' and no='8'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->fs9start->text() + "', end_time='" + ui->fs9end->text();
    sql = sql + "' where site='福山' and no='9'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;


    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm1start->text() + "', end_time='" + ui->jm1end->text();
    sql = sql + "' where site='即墨' and no='1'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm2start->text() + "', end_time='" + ui->jm2end->text();
    sql = sql + "' where site='即墨' and no='2'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm3start->text() + "', end_time='" + ui->jm3end->text();
    sql = sql + "' where site='即墨' and no='3'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm4start->text() + "', end_time='" + ui->jm4end->text();
    sql = sql + "' where site='即墨' and no='4'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm5start->text() + "', end_time='" + ui->jm5end->text();
    sql = sql + "' where site='即墨' and no='5'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm6start->text() + "', end_time='" + ui->jm6end->text();
    sql = sql + "' where site='即墨', and no='6'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm7start->text() + "', end_time='" + ui->jm7end->text();
    sql = sql + "' where site='即墨' and no='7'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm8start->text() + "', end_time='" + ui->jm8end->text();
    sql = sql + "' where site='即墨' and no='8'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;

    sql = "update m_time_table set start_time='";
    sql = sql + ui->jm9start->text() + "', end_time='" + ui->jm9end->text();
    sql = sql + "' where site='即墨' and no='9'";
    tmp.exec(sql);
    qDebug()<< "更新："<<temp <<" " << sql << " \n" ;



    tep.setText("保存成功！");
    tep.exec();
    
    return ;
}

void MainWindow::setDb()
{
    if(ok)
    {
        db.close();
        ok = false;
    }
    setLiteDb setlite;
    setlite.exec();
    openDb();
}

void MainWindow::setCheck()
{
    setcheck check;
    check.exec();
}
