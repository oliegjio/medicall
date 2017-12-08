#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include "QLabel"
#include "QVBoxLayout"
#include "QLineEdit"
#include "QPushButton"
#include "QNetworkRequest"
#include "QNetworkReply"
#include "QHttpPart"

#include "networkmanager.h"

class LoginView : public QWidget
{
    Q_OBJECT

private slots:
    void loginClicked();
    void backClicked();
    void loginRequestFinished(QNetworkReply* reply);

signals:
    void switchToLoginView();
    void switchToWelcomeView();
    void loggedIn(QString token, QString userData);

public:
    LoginView(QWidget* parent = 0);
    ~LoginView();

private:
    QNetworkAccessManager* loginNetworkManager;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINVIEW_H
