#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "httpget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void OnbutClink();
    void butclink();
    void Settext(const QString &text);
private:
    Ui::MainWindow *ui;
    HttpGet http;
};

#endif // MAINWINDOW_H
