#include "httpget.h"

HttpGet::HttpGet(QObject *parent) : QObject(parent)
{
}

HttpGet::HttpGet(const QString & url,QString  session,QObject * parent): QObject(parent)
{
    this->request.setUrl(url);
    if (session != "")
    {
        this->request.setHeader(QNetworkRequest::CookieHeader,session);
    }
}

HttpGet::~HttpGet()
{
}

void HttpGet::setUrl(const QUrl &url)
{
    this->request.setUrl(url);
}

void HttpGet::setUserAgent(const QString &userAgent)
{
    this->request.setHeader(QNetworkRequest::UserAgentHeader,userAgent);
}

void HttpGet::setSession(QString &session)
{
    this->request.setHeader(QNetworkRequest::CookieHeader,session);
}

QString HttpGet::httpGet()
{
    qDebug() << "httpGet()";
    QString tem;
    QNetworkAccessManager manger;
    this->reply = manger.get(this->request);
    connect(reply, &QNetworkReply::finished, [=](){QString temp(reply->readAll()); tem = temp;});
    reply->deleteLater();
    return tem;
}

QString HttpGet::httpGet(const QUrl & url,QString  session)
{
    qDebug() << "httpGet(const QUrl & url,QString  session)";
    this->request.setUrl(url);
    if (session != "")
    {
        this->request.setHeader(QNetworkRequest::CookieHeader,session);
    }
    QString tem;
    QNetworkAccessManager manger;
    this->reply = manger.get(this->request);
    connect(reply, &QNetworkReply::finished, [=](){QString temp(reply->readAll()); tem = temp;});
    reply->deleteLater();
    return tem;
}

QString HttpGet::httpGet(const QNetworkRequest & Request)
{
    QString tem;
    QNetworkAccessManager manger;
    this->reply = manger.get(Request);
    connect(reply, &QNetworkReply::finished, [=](){QString temp(reply->readAll()); tem = temp;});
    reply->deleteLater();
    return tem;
}

void HttpGet::startGet()
{
    qDebug() << "startGet()";
    QNetworkAccessManager manger;
    this->reply = manger.get(this->request);
    connect(reply, &QNetworkReply::finished, [=](){/*QString temp(reply->readAll()); tem = std::move(temp);*/emit(GetBack(reply->readAll()));});
    reply->deleteLater();
}

