#include "httpget.h"

HttpGet::HttpGet(Qobject * parent) : QObject(parent)
{
    this->manger = new QNetworkAccessManager;
    this->reply = new QNetworkReply;
    this->request = new QNetworkRequest;
}

HttpGet::HttpGet(const QString & url,QString & session = "",Qobject * parent = 0): QObject(parent)
{
    this->manger = new QNetworkAccessManager;
    this->reply = new QNetworkReply;
    this->request = new QNetworkRequest(url);
    if (session != "")
    {
        this->request->	setHeader(QNetworkRequest::CookieHeader,session);
    }
}

HttpGet::~httpGet()
{
    delete this->reply;
    delete this->request;
    delete this->manger;
}

void HttpGet::setUrl(const QUrl &url)
{
    this->request->setUrl(url);
}

void HttpGet::setUserAgent(const QString &userAgent)
{
    this->request->setHeader(QNetworkRequest::UserAgentHeader,userAgent);
}

void HttpGet::setSession(QString &session)
{
    this->request->	setHeader(QNetworkRequest::CookieHeader,session);
}


