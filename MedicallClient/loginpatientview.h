#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>

#include "networkmanager.h"

class LoginPatientView : public QWidget
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
    LoginPatientView(QWidget* parent = 0);
    ~LoginPatientView();

private:
    QNetworkAccessManager* login_NetworkManager;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINVIEW_H
