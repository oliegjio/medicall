#include "NetworkManager.h"

QNetworkReply* NetworkManager::postForm(QNetworkAccessManager* manager,
                                        const QUrl& url,
                                        const QMap<QString, QString>& data)
{
    QNetworkRequest request(url);

    QHttpMultiPart* multiPart = new QHttpMultiPart(manager);

    QMap<QString, QString>::const_iterator i;
    for (i = data.begin(); i != data.end(); i++)
    {
        QHttpPart part;
        QVariant header("form-data; name=\"" + i.key() + "\"");

        part.setHeader(QNetworkRequest::ContentDispositionHeader, header);
        part.setBody(i.value().toLatin1());

        multiPart->append(part);
    }

    return manager->post(request, multiPart);
}

QNetworkReply* NetworkManager::postEmpy(QNetworkAccessManager* manager, const QUrl& url)
{
    QNetworkRequest request(url);

    return manager->post(request, new QHttpMultiPart());
}

QNetworkReply* NetworkManager::postJson(QNetworkAccessManager* manager,
                                        const QUrl& url,
                                        const QJsonObject& data)
{
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument document(data);
    QByteArray array = document.toJson();

    return manager->post(request, array);
}

QNetworkReply* NetworkManager::postJsonToken(QNetworkAccessManager* manager,
                                             const QUrl& url,
                                             const QString& token)
{
    QNetworkRequest request(url);

    QByteArray authHeader("Bearer " + token.toUtf8());
    request.setRawHeader(QByteArray("Authorization"), authHeader);

    return manager->post(request, QByteArray());
}

QVariantHash NetworkManager::jsonToHash(QByteArray& rawData)
{
    QJsonDocument document = QJsonDocument::fromJson(rawData);
    QVariantHash object = document.object().toVariantHash();

    return object;
}

QVariantHash NetworkManager::processReply(QNetworkReply *reply)
{
    QVariantHash invalid = QVariantHash();
    invalid["status"] = QVariant().Invalid;

    if (reply->error()) {
        QString error = reply->errorString();
        qDebug() << error;
        invalid["error"] = QVariant(error);
        return invalid;
    }

    QByteArray replyData = reply->readAll();

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid() || replyData.isEmpty())
    {
        invalid["error"] = QVariant("Invalid or Empty reply!");
        return invalid;
    }

    QVariantHash data = NetworkManager::jsonToHash(replyData);

    return data;
}
