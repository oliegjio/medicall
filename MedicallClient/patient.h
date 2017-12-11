#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "networkmanager.h"
#include "loginpatientview.h"

class Patient : public QObject
{
    Q_OBJECT

private:
    Patient();
    static Patient* instance;

public:
    static Patient* getInstance();
    void initPatient(QVariantHash data);

    QString id;
    QString token;
    QString username;
    QString email;
    QString fullName;
    QString weight;
    QString height;
    QString bloodType;
    QString gender;
    QString location;
    QString birthDate;
    QString password;
};

#endif // PATIENT_H
