#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QObject>

#include "networkmanager.h"
#include "loginview.h"

class Patient : public QObject
{
    Q_OBJECT

public slots:
    void getPatient(QVariantHash data);

private slots:
    void getPatient_Finished(QNetworkReply* reply);

public:
    Patient(QWidget* parent = 0);
    ~Patient();

private:
    QString token;

    QString username;
    QString fullName;
    QString weight;
    QString height;
    QString bloodType;
    QString gender;
    QString location;
    QString birthDate;
    QString password;

    QNetworkAccessManager* getPatient_NetworkManager;

private:
    NetworkManager* network;
};

#endif // PATIENT_H
