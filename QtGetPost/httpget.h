#ifndef HTTPGET_H
#define HTTPGET_H

#include <QtCore>
#include <QtNetwork>


class HttpGet : public  QObject
{
    Q_OBJECT
public:
    HttpGet(Qobject * parent = 0);
    HttpGet(const QString & url,QString & session = "",Qobject * parent = 0);
  //  void setUrl(const QString & url);
    void setUrl(const QUrl & url);
    void setSession(QString & session);
    void setUserAgent(const QString & userAgent);
    QString httpGet();
    QString httpGet(const QUrl & url,QString & session = "");
    QString httpGet(const QNetworkReply & Reply);
    void startGet();
    ~httpGet();
Q_SIGNALS:
    void GetBack(QString & back);
private:
    QNetworkAccessManager * manger;
    QNetworkReply * reply;
    QNetworkRequest * request;
};

#endif // HTTPGET_H
