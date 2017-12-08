#include "patient.h"

Patient::Patient(QWidget* parent) : QObject(parent) {}

Patient::~Patient() {}

void Patient::initPatient(QVariantHash data)
{
    token = data["token"].value<QString>();

    QHash<QString, QVariant> user = data["user"].toHash();

    username = user["username"].value<QString>();
    fullName = user["fullName"].value<QString>();
    weight = user["weight"].value<QString>();
    bloodType = user["bloodType"].value<QString>();
    location = user["location"].value<QString>();
    height = user["height"].value<QString>();
    gender = user["gender"].value<QString>();
    birthDate = user["birthDate"].value<QString>();
    password = user["password"].value<QString>();
}


