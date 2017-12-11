#include "doctor.h"

Doctor::Doctor() {}

Doctor* Doctor::getInstance()
{
    if (instance == 0)
    {
        instance = new Doctor();
    }
    return instance;
}

Doctor* Doctor::instance = 0;

void Doctor::initDoctor(QVariantHash data)
{
    token = data["token"].value<QString>();

    QHash<QString, QVariant> user = data["doctor"].toHash();

    id = user["id"].value<QString>();
    username = user["username"].value<QString>();
    fullName = user["fullName"].value<QString>();
    socialNetworks = user["socialNetworks"].value<QString>();
    phoneNumber = user["phoneNumber"].value<QString>();
    speciality = user["speciality"].value<QString>();
    password = user["password"].value<QString>();
    email = user["email"].value<QString>();
}


