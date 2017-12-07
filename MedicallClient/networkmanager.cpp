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

QNetworkRequest* NetworkManager::postForm(const QUrl& url, const QHash<QString, QString>& data)
{
    QNetworkRequest request(url);

    QHttpMultiPart* multiPart = new QHttpMultiPart(instance);

    QHash<QString, QString>::const_iterator i;
    for (i = data.begin(); i != data.end(); i++)
    {
        QHttpPart part;
        QVariant header("form-data; name=\"" + i.key() + "\"");

        part.setHeader(QNetworkRequest::ContentDispositionHeader, header);
        part.setBody(i.value().toLatin1());

        multiPart->append(part);
    }

    instance->post(request, multiPart);

    return &request;
}

QNetworkRequest* NetworkManager::postJson(const QUrl& url, const QJsonObject& data)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument document(data);
    QByteArray array = document.toJson();

    instance->post(request, array);

    return &request;
}

QMap<QString, QString> NetworkManager::getReplyData(QNetworkReply* reply)
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
