#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dbclass.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;
    dbClass * litedb;

public slots:
    void SetTime();
    void setDb();
    void setCheck();

protected:
    void upTime();
    void openDb();
    
private:
    Ui::MainWindow *ui;
    bool ok;
};

#endif // MAINWINDOW_H
