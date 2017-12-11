#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QObject>
#include <QNetworkReply>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "NetworkManager.h"
#include "PatientLogin_View.h"

class Patient_Model : public QObject
{
    Q_OBJECT

private:
    Patient_Model();
    static Patient_Model* instance;

public:
    static Patient_Model* getInstance();
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
