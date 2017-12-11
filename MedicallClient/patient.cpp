#include "patient.h"

Patient::Patient() {}

Patient* Patient::getInstance()
{
    if (instance == 0)
    {
        instance = new Patient();
    }
    return instance;
}

Patient* Patient::instance = 0;

void Patient::initPatient(QVariantHash data)
{
    token = data["token"].value<QString>();

    QHash<QString, QVariant> user = data["patient"].toHash();

    id = user["id"].value<QString>();
    username = user["username"].value<QString>();
    fullName = user["fullName"].value<QString>();
    weight = user["weight"].value<QString>();
    bloodType = user["bloodType"].value<QString>();
    location = user["location"].value<QString>();
    height = user["height"].value<QString>();
    gender = user["gender"].value<QString>();
    birthDate = user["birthDate"].value<QString>();
    password = user["password"].value<QString>();
    email = user["email"].value<QString>();
}


