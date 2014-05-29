#ifndef SETLITEDB_H
#define SETLITEDB_H

#include <QDialog>
#include <QtSql>
#include "dbclass.h"

namespace Ui {
class setLiteDb;
}

class setLiteDb : public QDialog
{
    Q_OBJECT
    
public:
    explicit setLiteDb(QWidget *parent = 0);
    ~setLiteDb();

protected slots:
    void testDb();
    void setDb();
    
private:
    Ui::setLiteDb *ui;
    dbClass * db;
    QSqlDatabase test;

};

#endif // SETLITEDB_H
