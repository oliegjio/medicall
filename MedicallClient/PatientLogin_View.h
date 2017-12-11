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
    void backButton_Clicked();
    void loggedIn_Event(QVariantHash& data);

public:
    PatientLogin_View(QWidget* parent = 0);
    ~PatientLogin_View();

private:
    QNetworkAccessManager* login_NetworkManager;
    QLineEdit* username_Line;
    QLineEdit* password_Line;
};

#endif // LOGINVIEW_H
