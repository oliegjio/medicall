#include "MainWindow.h"

MainWindow::MainWindow()
{
    // #####
    // ## Setup:
    // #####

    patient = Patient_Model::getInstance();
    doctor = Doctor_Model::getInstance();

    resize(QDesktopWidget().availableGeometry(this).size() * 0.6);
    setWindowTitle("Medicall");

    stack = new QStackedWidget();

    setCentralWidget(stack);

    QFont defaultFont("Arial", 15);
    setFont(defaultFont);

    // #####
    // ## Stack:
    // #####

    // # 0
    // # Welcome View:
    Welcome_View* welcomeView = new Welcome_View(this);
    stack->addWidget(welcomeView);

    connect(welcomeView,
            &Welcome_View::patientLoginButton_Clicked,
            this,
            &MainWindow::switchToLoginPatientView);
    connect(welcomeView,
            &Welcome_View::doctorLoginButton_Clicked,
            this,
            &MainWindow::switchToLoginDoctorView);
    connect(welcomeView,
            &Welcome_View::patientLoginButton_Clicked,
            this,
            &MainWindow::switchToPatientRegistrationView);
    connect(welcomeView,
            &Welcome_View::doctorRegisterButton_Clicked,
            this,
            &MainWindow::switchToDoctorRegistrationView);
    connect(welcomeView,
            &Welcome_View::exitButton_Clicked,
            this,
            &QMainWindow::close);

    // # 1
    // # Login Patient View:
    PatientLogin_View* loginPatientView = new PatientLogin_View(this);
    stack->addWidget(loginPatientView);
    connect(loginPatientView,
            &PatientLogin_View::backButton_Clicked,
            this,
            &MainWindow::switchToWelcomeView);
    connect(loginPatientView,
            &PatientLogin_View::loggedIn_Event,
            this,
            &MainWindow::switchToPatientView);

    // # 2
    // # Login Doctor View:
    DoctorLogin_VIew* loginDoctorView = new DoctorLogin_VIew(this);
    stack->addWidget(loginDoctorView);
    connect(loginDoctorView,
            &DoctorLogin_VIew::backButton_Clicked,
            this,
            &MainWindow::switchToWelcomeView);
    connect(loginDoctorView,
            &DoctorLogin_VIew::loggedIn_Event,
            this,
            &MainWindow::switchToDoctorView);

    // # 3
    // # Patient Registration View:
    PatientRegistration_View* patientRegistrationView = new PatientRegistration_View(this);
    stack->addWidget(patientRegistrationView);
    connect(patientRegistrationView,
            &PatientRegistration_View::backButton_Clicked,
            this,
            &MainWindow::switchToWelcomeView);
    connect(patientRegistrationView,
            &PatientRegistration_View::registered_Event,
            this,
            &MainWindow::patientRegistration_Finished);

    // # 4
    // # Doctor Registration View:
    DoctorRegistration_View* doctorRegistrationView = new DoctorRegistration_View(this);
    stack->addWidget(doctorRegistrationView);
    connect(doctorRegistrationView,
            &DoctorRegistration_View::backButton_Clicked,
            this,
            &MainWindow::switchToWelcomeView);
    connect(doctorRegistrationView,
            &DoctorRegistration_View::registered_Event,
            this,
            &MainWindow::doctorRegistration_Finished);


    // # 5
    // # Patient View:
    patient_View = new Patient_View(this);
    stack->addWidget(patient_View);
    connect(patient_View,
            &Patient_View::backButton_Clicked,
            this,
            &MainWindow::switchToWelcomeView);
    connect(patient_View,
            &Patient_View::takeSurveyButton_Clicked,
            this,
            &MainWindow::switchToSurveyView);

    // # 6
    // # Doctor View:
    doctor_View = new Doctor_View(this);
    stack->addWidget(doctor_View);
    connect(doctor_View,
            &Doctor_View::backButton_Clicked,
            this,
            &MainWindow::switchToWelcomeView);

    // # 7
    // # Survey View:
    survey_View = new Survey_View(this);
    stack->addWidget(survey_View);
    connect(survey_View,
            &Survey_View::backButton_Clicked,
            [=] () { stack->setCurrentIndex(5); });

    // #####
    // ## Other:
    // #####

    setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow() {}

void MainWindow::switchToWelcomeView() { stack->setCurrentIndex(0); }

void MainWindow::switchToLoginPatientView() { stack->setCurrentIndex(1); }

void MainWindow::switchToLoginDoctorView() { stack->setCurrentIndex(2); }

void MainWindow::switchToPatientRegistrationView() { stack->setCurrentIndex(3); }

void MainWindow::switchToDoctorRegistrationView() { stack->setCurrentIndex(4); }

void MainWindow::switchToSurveyView() { stack->setCurrentIndex(7); }

void MainWindow::switchToPatientView(QVariantHash data)
{
    patient->init(data);
    patient_View->init();
    stack->setCurrentIndex(5);
}

void MainWindow::switchToDoctorView(QVariantHash data)
{
    doctor->initDoctor(data);
    doctor_View->init();
    stack->setCurrentIndex(6);
}

void MainWindow::patientRegistration_Finished(QVariantHash data)
{
    switchToLoginPatientView();
    patient->init(data);
}

void MainWindow::doctorRegistration_Finished(QVariantHash data)
{
    switchToLoginDoctorView();
    doctor->initDoctor(data);
}
