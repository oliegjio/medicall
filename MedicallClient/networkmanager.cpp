#include "networkmanager.h"

NetworkManager* NetworkManager::instance = 0;

NetworkManager* NetworkManager::getInstance()
{
    if (instance == 0)
    {
        instance = new NetworkManager();
    }

    return instance;
}

NetworkManager::NetworkManager() {}

QNetworkReply* NetworkManager::postForm(const QUrl& url, const QMap<QString, QString>& data)
{
    QNetworkRequest request(url);

    QHttpMultiPart* multiPart = new QHttpMultiPart(instance);

    QMap<QString, QString>::const_iterator i;
    for (i = data.begin(); i != data.end(); i++)
    {
        QHttpPart part;
        QVariant header("form-data; name=\"" + i.key() + "\"");

        part.setHeader(QNetworkRequest::ContentDispositionHeader, header);
        part.setBody(i.value().toLatin1());

        multiPart->append(part);
    }

    return instance->post(request, multiPart);
}

QNetworkReply* NetworkManager::postEmpy(const QUrl& url)
{
    QNetworkRequest request(url);

    return instance->post(request, new QHttpMultiPart());
}

QNetworkReply* NetworkManager::postJson(const QUrl& url, const QJsonObject& data)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument document(data);
    QByteArray array = document.toJson();

    return instance->post(request, array);
}

QMap<QString, QString> NetworkManager::getJsonReplyData(QNetworkReply* reply)
{
    QString rawData = reply->readAll();
    QJsonDocument document = QJsonDocument::fromJson(rawData.toUtf8());
    QJsonObject object = document.object();

    QMap<QString, QString> data;

    QJsonObject::iterator i;
    for (i = object.begin(); i != object.end(); i++)
    {
        data[i.key()] = i.value().toString();
    }

    return data;
}

QNetworkReply* NetworkManager::postJsonToken(const QUrl& url, const QJsonObject& data, const QString& token)
{
    QNetworkRequest request(url);
    request.setRawHeader(QByteArray("Authorization"), QByteArray("Bearer " + token.toUtf8()));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument document(data);
    QByteArray array = document.toJson();

    return instance->post(request, array);
}
