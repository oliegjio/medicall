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

public slots:
    void initPatient(QVariantHash data);

private:
    Patient();
    static Patient* instance;

public:
    static Patient* getInstance();

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
