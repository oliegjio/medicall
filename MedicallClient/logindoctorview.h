#ifndef LOGINDOCTORVIEW_H
#define LOGINDOCTORVIEW_H

#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>

#include "networkmanager.h"

class LoginDoctorView : public QWidget
{
    Q_OBJECT

private slots:
    void login_Finished(QNetworkReply* reply);
    void loginButton_Clicked();

signals:
    void switchToLoginView();
    void backButton_Event();
    void loggedIn(QVariantHash& data);

public:
    LoginDoctorView(QWidget* parent = 0);
    ~LoginDoctorView();

private:
    QNetworkAccessManager* login_NetworkManager;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINDOCTORVIEW_H
