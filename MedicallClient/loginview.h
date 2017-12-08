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

class LoginView : public QWidget
{
    Q_OBJECT

private slots:
    void loginButton_Clicked();
    void backButton_Clicked();
    void login_Finished(QNetworkReply* reply);

signals:
    void switchToLoginView();
    void backButton_Event();
    void loggedIn(QVariantHash data);

public:
    LoginView(QWidget* parent = 0);
    ~LoginView();

private:
    QNetworkAccessManager* login_NetworkManager;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINVIEW_H
