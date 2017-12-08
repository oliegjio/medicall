#include "patient.h"

Patient::Patient(QWidget* parent) : QObject(parent)
{
    getPatient_NetworkManager = new QNetworkAccessManager();
    connect(getPatient_NetworkManager, &QNetworkAccessManager::finished, this, &Patient::getPatient_Finished);
}

Patient::~Patient() {}

void Patient::getPatient(QVariantHash data)
{
    QString id = data["user"].toHash()["id"].value<QString>();
    token = data["token"].value<QString>();

    QUrl url("http://localhost:8000/user/" + id);

    NetworkManager::postJsonToken(getPatient_NetworkManager, url, token);
}

void Patient::getPatient_Finished(QNetworkReply *reply)
{
    QByteArray array(reply->readAll());
    QVariantHash data = NetworkManager::jsonToHash(array);

    username = data["username"].value<QString>();
    fullName = data["fullName"].value<QString>();
    weight = data["weight"].value<QString>();
    bloodType = data["bloodType"].value<QString>();
    location = data["location"].value<QString>();
    height = data["height"].value<QString>();
    gender = data["gender"].value<QString>();
    birthDate = data["birthDate"].value<QString>();
    password = data["password"].value<QString>();
}

