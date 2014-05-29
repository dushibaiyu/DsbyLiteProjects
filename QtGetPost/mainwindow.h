#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>

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
    void OnPostClink();
    void Settext();
private:
    QNetworkAccessManager manager;
    Ui::MainWindow *ui;
    QNetworkReply * reply;
};

#endif // MAINWINDOW_H
