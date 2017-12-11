#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "networkmanager.h"
#include "logindoctorview.h"

class Doctor : public QObject
{
    Q_OBJECT

public slots:
    void initDoctor(QVariantHash data);

private:
    Doctor();
    static Doctor* instance;

public:
    static Doctor* getInstance();

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
