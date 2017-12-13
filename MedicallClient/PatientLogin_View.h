#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QVBoxLayout>
#include <QLineEdit>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QHttpPart>

#include "NetworkManager.h"
#include "Modal.h"
#include "Button.h"
#include "LineEdit.h"
#include "Label.h"

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
    LineEdit* username_Line;
    LineEdit* password_Line;
};

#endif // LOGINVIEW_H
