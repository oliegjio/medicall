#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QHttpMultiPart>
#include <QHttpPart>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonArray>

class NetworkManager : public QObject
{
    Q_OBJECT

private:
    static QMap<QString, QString> parseJsonToMap(QJsonObject& object);

public:
    static int const ERR_CONNECTION = 0;
    static int const ERR_CREDENTIALS = 401;
    static int const ERR_SERVER = 400;
    static int const ERR_DATABASE = 406;
    static int const ERR_UNKNOWN = 3;

    static QNetworkReply* postForm(QNetworkAccessManager* manager,
                                   const QUrl& url,
                                   const QMap<QString, QString>& data);

    static QNetworkReply* postEmpy(QNetworkAccessManager* manager,
                                   const QUrl& url);

    static QNetworkReply* postJson(QNetworkAccessManager* manager,
                                   const QUrl& url,
                                   const QJsonObject& data);

    static QNetworkReply* postJsonToken(QNetworkAccessManager* manager,
                                        const QUrl& url,
                                        const QString& token);

    static QVariantHash jsonToHash(QByteArray& reply);

    static QVariantHash processReply(QNetworkReply* reply);
};

#endif // NETWORKMANAGER_H
