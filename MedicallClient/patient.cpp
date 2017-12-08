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

    NetworkManager::postJsonToken(getPatientNetworkManager, QUrl("http://localhost:8000/user/"), token);
}

void Patient::getPatientFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
//    QMap<QString, QString> data = NetworkManager::getReplyData(reply);
//    username = data["username"];
}

