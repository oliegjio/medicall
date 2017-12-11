#ifndef DOCTORREGISTRATIONVIEW_H
#define DOCTORREGISTRATIONVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

#include "NetworkManager.h"

class DoctorRegistration_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Clicked();
    void registered_Event(QVariantHash data);

private slots:
    void registerButton_Clicked();
    void register_Finished(QNetworkReply* reply);

public:
    DoctorRegistration_View(QWidget* parent = 0);
    ~DoctorRegistration_View();

private:
    QLineEdit* fullName_Line;
    QLineEdit* username_Line;
    QLineEdit* email_Line;
    QLineEdit* password1_Line;
    QLineEdit* password2_Line;
    QLineEdit* speciality_Line;
    QLineEdit* phoneNumber_Line;
    QLineEdit* socialNetworks_Line;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // DOCTORREGISTRATIONVIEW_H
