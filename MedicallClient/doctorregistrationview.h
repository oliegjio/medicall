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

#include "networkmanager.h"

class DoctorRegistrationView : public QWidget
{
    Q_OBJECT

signals:
    void backButton_Event();

private slots:
    void registerButton_Clicked();
    void backButton_Clicked();
    void register_Finished(QNetworkReply* reply);

public:
    DoctorRegistrationView(QWidget* parent = 0);
    ~DoctorRegistrationView();

private:
    QLineEdit* fullNameLine;
    QLineEdit* usernameLine;
    QLineEdit* emailLine;
    QLineEdit* password1Line;
    QLineEdit* password2Line;
    QLineEdit* specialityLine;
    QLineEdit* phoneNumberLine;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // DOCTORREGISTRATIONVIEW_H
