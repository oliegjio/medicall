#ifndef DOCTORREGISTRATIONVIEW_H
#define DOCTORREGISTRATIONVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>

#include "NetworkManager.h"
#include "Button.h"
#include "LineEdit.h"

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
    LineEdit* fullName_Line;
    LineEdit* username_Line;
    LineEdit* email_Line;
    LineEdit* password1_Line;
    LineEdit* password2_Line;
    LineEdit* speciality_Line;
    LineEdit* phoneNumber_Line;
    LineEdit* socialNetworks_Line;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // DOCTORREGISTRATIONVIEW_H
