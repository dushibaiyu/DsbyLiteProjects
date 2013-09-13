#ifndef HTTPGET_H
#define HTTPGET_H

#include <QtCore>
#include <QtNetwork>

class HttpGet : public  QObject
{
    Q_OBJECT
public:
    HttpGet(QObject * parent = 0);
    HttpGet(const QString & url, QString session = "", QObject *parent = 0);
    void setUrl(const QUrl & url);
    void setSession(QString & session);
    void setUserAgent(const QString & userAgent);
    QString httpGet();
    QString httpGet(const QUrl & url,QString  session = "");
    QString httpGet(const QNetworkRequest & Request);
    void startGet();
    ~HttpGet();
public slots:
    void getFinished();
Q_SIGNALS:
    void GetBack(const QString & back);
private:
    QNetworkRequest request;
    QNetworkReply * reply;
    QString * data;
};

#endif // HTTPGET_H
