#ifndef SINGIN_H
#define SINGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "dbclass.h"


namespace Ui {
class singin;
}

class singin : public QDialog
{
    Q_OBJECT
    
public:
    explicit singin(QWidget *parent = 0);
    ~singin();
    dbClass * litedb;

public slots:
    void Singin();
    
private:
    Ui::singin *ui;
    MainWindow * mainwindow;
};

#endif // SINGIN_H
