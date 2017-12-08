#include "patient.h"

Patient::Patient(QWidget* parent) : QObject(parent)
{
    network = NetworkManager::getInstance();
    connect(network, &NetworkManager::finished, this, &Patient::getPatientFinished);
}

Patient::~Patient() {}

void Patient::getPatient(QString token)
{
    this->token = token;

    network->postJsonToken(QUrl("http://localhost:8000/user/"), QJsonObject{}, token);
}

void Patient::getPatientFinished(QNetworkReply *reply)
{
    qDebug() << reply->readAll();
//    QMap<QString, QString> data = NetworkManager::getReplyData(reply);
//    username = data["username"];
}

