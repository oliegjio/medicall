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
#include "doctorview.h"
#include "surveyview.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void switchToWelcomeView();
    void switchToLoginPatientView();
    void switchToLoginDoctorView();
    void switchToPatientRegistrationView();
    void switchToDoctorRegistrationView();
    void switchToSurveyView();
    void switchToPatientView(QVariantHash data);
    void switchToDoctorView(QVariantHash data);

private slots:
    void patientRegistration_Finished(QVariantHash data);
    void doctorRegistration_Finished(QVariantHash data);

public:
    MainWindow();
    ~MainWindow();

    QStackedWidget* stack;

private:
    PatientView* patientView;
    DoctorView* doctorView;
    Patient* patient;
    Doctor* doctor;
    SurveyView* surveyView;
};

#endif // MAINWINDOW_H
