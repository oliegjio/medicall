#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QLabel>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>

#include "NetworkManager.h"

class PatientLogin_View : public QWidget
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
    PatientLogin_View(QWidget* parent = 0);
    ~PatientLogin_View();

private:
    QNetworkAccessManager* login_NetworkManager;
    QLineEdit* usernameLine;
    QLineEdit* passwordLine;
};

#endif // LOGINVIEW_H
