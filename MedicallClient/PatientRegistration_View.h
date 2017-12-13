#ifndef PATIENTREGISTRATIONVIEW_H
#define PATIENTREGISTRATIONVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QDoubleValidator>

#include "NetworkManager.h"
#include "Button.h"
#include "LineEdit.h"
#include "Label.h"

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
    LineEdit* fullName_Line;
    LineEdit* username_Line;
    LineEdit* email_Line;
    LineEdit* password1_Line;
    LineEdit* password2_Line;
    QDateTimeEdit* birthDate_Line;
    LineEdit* location_Line;
    QComboBox* gender_Line;
    LineEdit* weight_Line;
    LineEdit* height_Line;
    QComboBox* bloodType_Line;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // PATIENTREGISTRATIONVIEW_H
