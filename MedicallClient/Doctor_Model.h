#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "NetworkManager.h"
#include "DoctorLogin_View.h"

class Doctor_Model : public QObject
{
    Q_OBJECT

public slots:
    void initDoctor(QVariantHash data);

private:
    Doctor_Model();
    static Doctor_Model* instance;

public:
    static Doctor_Model* getInstance();

    QString id;
    QString token;
    QString username;
    QString email;
    QString fullName;
    QString phoneNumber;
    QString speciality;
    QString socialNetworks;
    QString birthDate;
    QString password;
};

#endif // DOCTOR_H
