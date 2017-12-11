#ifndef PATIENTREGISTRATIONVIEW_H
#define PATIENTREGISTRATIONVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QDoubleValidator>
#include <QPushButton>

#include "NetworkManager.h"

class PatientRegistration_View : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Clicked();
    void registered_Event(QVariantHash& data);

private slots:
    void registerButton_Clicked();
    void register_Finished(QNetworkReply* reply);

public:
    PatientRegistration_View(QWidget* parent = 0);
    ~PatientRegistration_View();

private:
    QLineEdit* fullName_Line;
    QLineEdit* username_Line;
    QLineEdit* email_Line;
    QLineEdit* password1_Line;
    QLineEdit* password2_Line;
    QDateTimeEdit* birthDate_Line;
    QLineEdit* location_Line;
    QComboBox* gender_Line;
    QLineEdit* weight_Line;
    QLineEdit* height_Line;
    QComboBox* bloodType_Line;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // PATIENTREGISTRATIONVIEW_H
