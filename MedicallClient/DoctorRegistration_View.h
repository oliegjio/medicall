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
    void backButton_Event();
    void registered(QVariantHash data);

private slots:
    void registerButton_Clicked();
    void register_Finished(QNetworkReply* reply);

public:
    DoctorRegistration_View(QWidget* parent = 0);
    ~DoctorRegistration_View();

private:
    QLineEdit* fullNameLine;
    QLineEdit* usernameLine;
    QLineEdit* emailLine;
    QLineEdit* password1Line;
    QLineEdit* password2Line;
    QLineEdit* specialityLine;
    QLineEdit* phoneNumberLine;
    QLineEdit* socialNetworksLine;

    QNetworkAccessManager* register_NetworkManager;
};

#endif // DOCTORREGISTRATIONVIEW_H
