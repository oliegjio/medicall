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
    void getPatient(QString token, QString userData);

private slots:
    void getPatientFinished(QNetworkReply* reply);

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

    QNetworkAccessManager* getPatientNetworkManager;

private:
    NetworkManager* network;
};

#endif // PATIENT_H
