#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>

class NetworkManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    static NetworkManager* getInstance();

    static QNetworkRequest* postForm(const QUrl& url, const QHash<QString, QString>& data);
    static QNetworkRequest* postJson(const QUrl& url, const QJsonObject& data);
    static QMap<QString, QString> getReplyData(QNetworkReply* reply);

private:
    NetworkManager();

    static NetworkManager* instance;
};

#endif // NETWORKMANAGER_H
