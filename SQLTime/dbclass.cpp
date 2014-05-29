#include "dbclass.h"

dbClass * dbClass::tp = nullptr;

dbClass::dbClass()
{
    liteDb = QSqlDatabase::addDatabase("QSQLITE","liteDb");
    liteDb.setDatabaseName("singin.db");
    liteDb.open();
    upDate();
    aces = new AesHelper();
}

dbClass::~dbClass()
{
      liteDb.close();
      delete tp;
      delete aces;
      aces = nullptr;
      tp = nullptr;
}

dbClass * dbClass::getDbClass()
{
    if (nullptr == tp)
    {
        tp = new dbClass();
    }
    return tp;
}

QString dbClass::getCheck() const
{
    if (check == "")
    {
        return check;
    }
    return aces->aesUncrypt(check);
}
QString dbClass::getServer() const
{
    if (server == "")
    {
        return server;
    }
    return aces->aesUncrypt(server);
}
QString dbClass::getPort() const
{
    return port;
}
QString dbClass::getUsername() const
{
     if (username == "")
     {
         return username;
     }
     return aces->aesUncrypt(username);
}
QString dbClass::getPassword() const
{
     if (password == "")
     {
         return password;
     }
     return aces->aesUncrypt(password);
}
QString dbClass::getDbname() const
{
     if (dbname == "")
     {
         return dbname;
     }
     return aces->aesUncrypt(dbname);
}

void dbClass::SetCheck(QString check)
{
    if (check == "")
    {
        this->check.clear();
    }
    else
    {
        this->check = aces->aesEncrypt(check);
    }
}
void dbClass::setServer(QString server)
{
    if (server == "")
    {
        this->server == "";
    }
    else
    {
        this->server = aces->aesEncrypt(server);
    }
}
void dbClass::setPort(QString port)
{
    this->port = port;
}
void dbClass::setUsername(QString username)
{
    if (username == "")
    {
        this->username == "";
    }
    else
    {
        this->username = aces->aesEncrypt(username);
    }
}
void dbClass::setPassword(QString pass)
{
    if (pass == "")
    {
        this->password == "";
    }
    else
    {
        this->password = aces->aesEncrypt(pass);
    }
}
void dbClass::setDbname(QString dbname)
{
    if (dbname == "")
    {
        this->dbname == "";
    }
    else
    {
        this->dbname = aces->aesEncrypt(dbname);
    }
}

void dbClass::upDb()
{
    QSqlQuery tmp(liteDb);
    QString sql;
    sql = "update sett set valued='" + check + "' where indexed='check'";
    tmp.exec(sql);

    sql = "update sett set valued='" + server + "' where indexed='server'";
    tmp.exec(sql);

    sql = "update sett set valued='" + port + "' where indexed='port'";
    tmp.exec(sql);

    sql = "update sett set valued='" + username + "' where indexed='username'";
    tmp.exec(sql);

    sql = "update sett set valued='" + password + "' where indexed='password'";
    tmp.exec(sql);

    sql = "update sett set valued='" + dbname + "' where indexed='dbname'";
    tmp.exec(sql);
}

void dbClass::upDate()
{
    QSqlQuery select(liteDb);
    bool tm = select.exec("select * from sett");
    qDebug() <<"select sqlitedb:" << tm;
    if (tm)
    {
        while (select.next())
        {
            if(select.value("indexed").toString() == "check")
            {
                check = select.value("valued").toString();
                qDebug() << "select check:"<<check;
                continue;
            }
            if(select.value("indexed").toString() == "server")
            {
                server = select.value("valued").toString();
                continue;
            }
            if(select.value("indexed").toString() == "port")
            {
                port = select.value("valued").toString();
                continue;
            }
            if(select.value("indexed").toString() == "username")
            {
                username = select.value("valued").toString();
                continue;
            }
            if(select.value("indexed").toString() == "password")
            {
                password = select.value("valued").toString();
                continue;
            }
            if(select.value("indexed").toString() == "dbname")
            {
                dbname = select.value("valued").toString();
                continue;
            }
        }
    }
    else
    {
        check = "";
        server = "";
        port = "";
        username = "";
        password = "";
        select.exec("create table sett (indexed nvarchar(50) primary key,valued nvarchar)");
        select.exec("insert into sett (indexed) values ('check')");
        select.exec("insert into sett (indexed) values ('server')");
        select.exec("insert into sett (indexed) values ('port')");
        select.exec("insert into sett (indexed) values ('username')");
        select.exec("insert into sett (indexed) values ('password')");
        select.exec("insert into sett (indexed) values ('dbname')");
    }
}

