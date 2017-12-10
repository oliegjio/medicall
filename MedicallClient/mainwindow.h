#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QStackedWidget"
#include "QDesktopWidget"

#include "welcomeview.h"
#include "loginpatientview.h"
#include "patientregistrationview.h"
#include "doctorregistrationview.h"
#include "patientview.h"
#include "patient.h"
#include "logindoctorview.h"
#include "doctor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void switchToWelcomeView();
    void switchToLoginPatientView();
    void switchToLoginDoctorView();
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
