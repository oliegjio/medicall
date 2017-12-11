#include "Doctor_Model.h"

Doctor_Model::Doctor_Model() {}

Doctor_Model* Doctor_Model::getInstance()
{
    if (instance == 0)
    {
        instance = new Doctor_Model();
    }
    return instance;
}

Doctor_Model* Doctor_Model::instance = 0;

void Doctor_Model::initDoctor(QVariantHash data)
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


