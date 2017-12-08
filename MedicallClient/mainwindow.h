#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStackedWidget"
#include "QDesktopWidget"

#include "welcomeview.h"
#include "loginview.h"
#include "patientregistrationview.h"
#include "doctorregistrationview.h"
#include "patientview.h"
#include "patient.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void switchToWelcomeView();
    void switchToLoginView();
    void switchToPatientRegistrationView();
    void switchToDoctorRegistrationView();
    void switchToPatientView();

public:
    MainWindow();
    ~MainWindow();

    QStackedWidget* stack;

private:
    PatientView* patientView;
};

#endif // MAINWINDOW_H
