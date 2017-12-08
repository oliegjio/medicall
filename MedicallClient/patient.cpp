#include "patient.h"

Patient::Patient(QWidget* parent) : QObject(parent)
{
    getPatientNetworkManager = new QNetworkAccessManager();
    connect(getPatientNetworkManager, &QNetworkAccessManager::finished, this, &Patient::getPatientFinished);
}

Patient::~Patient() {}

void Patient::getPatient(QString token, QString userData)
{
//    QByteArray array(userData.toUtf8());
//    QMap<QString, QString> user = NetworkManager::jsonToMap(array);

    qDebug() << userData;

//    QUrl url("http://localhost:8000/user/" + userData["id"]);

//    NetworkManager::postJsonToken(getPatientNetworkManager, url, token);
}

void Patient::getPatientFinished(QNetworkReply *reply)
{
//    QByteArray rawData(reply->readAll());

//    QMap<QString, QString> data = NetworkManager::jsonToMap(rawData);

//    username = data["user"];

//    qDebug() << username;
}

