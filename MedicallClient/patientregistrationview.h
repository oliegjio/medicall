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

#include "networkmanager.h"

class PatientRegistrationView : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Event();
    void registered(QVariantHash& data);

private slots:
    void backButton_Clicked();
    void registerButton_Clicked();
    void register_Finished(QNetworkReply* reply);

public:
    PatientRegistrationView(QWidget* parent = 0);
    ~PatientRegistrationView();

private:
    QLineEdit* fullNameLine;
    QLineEdit* usernameLine;
    QLineEdit* emailLine;
    QLineEdit* password1Line;
    QLineEdit* password2Line;
    QDateTimeEdit* birthDateLine;
    QLineEdit* locationLine;
    QComboBox* genderLine;
    QLineEdit* weightLine;
    QLineEdit* heightLine;
    QComboBox* bloodTypeLine;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // PATIENTREGISTRATIONVIEW_H
