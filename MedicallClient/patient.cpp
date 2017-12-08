#include "patient.h"

Patient::Patient(QWidget* parent) : QObject(parent)
{
    getPatientNetworkManager = new QNetworkAccessManager();
    connect(getPatientNetworkManager, &QNetworkAccessManager::finished, this, &Patient::getPatientFinished);
}

Patient::~Patient() {}

void Patient::getPatient(QString token)
{
    this->token = token;

    NetworkManager::postJsonToken(getPatientNetworkManager, QUrl("http://localhost:8000/user/1"), token);
}

void Patient::getPatientFinished(QNetworkReply *reply)
{
    QByteArray rawData(reply->readAll());

    QMap<QString, QString> data = NetworkManager::jsonToMap(rawData);

    username = data["username"];

    qDebug() << username;
}

