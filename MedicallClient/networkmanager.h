#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QNetworkRequest>

class NetworkManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    static NetworkManager* getInstance();

    QNetworkReply* postForm(const QUrl& url, const QMap<QString, QString>& data);
    QNetworkReply* postEmpy(const QUrl& url);
    QNetworkReply* postJson(const QUrl& url, const QJsonObject& data);
    QNetworkReply* postJsonToken(const QUrl& url, const QJsonObject& data, const QString& token);

    static QMap<QString, QString> getJsonReplyData(QNetworkReply* reply);

private:
    NetworkManager();

    static NetworkManager* instance;
};

#endif // NETWORKMANAGER_H
