
#include <QApplication>
#include <QtSql>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "singin.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    singin yy;
    yy.show();


    return a.exec();
}
