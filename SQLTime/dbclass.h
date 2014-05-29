#ifndef DBCLASS_H
#define DBCLASS_H
#include <QtSql>
#include <QString>
#include <QMessageBox>
#include "aeshelper.h"

class dbClass
{
    dbClass();
    static dbClass * tp;
    QString check;
    QString server;
    QString port;
    QString username;
    QString password;
    QString dbname;
    QSqlDatabase liteDb;
    bool ok;
    AesHelper * aces;

public:
    static dbClass * getDbClass();

    QString getCheck()const;
    QString getServer()const;
    QString getPort()const;
    QString getUsername()const;
    QString getPassword()const;
    QString getDbname() const;

    void SetCheck(QString);
    void setServer(QString);
    void setPort(QString);
    void setUsername(QString);
    void setPassword(QString);
    void setDbname(QString);

    void upDb();
    void upDate();

    ~dbClass();

};

#endif // DBCLASS_H
