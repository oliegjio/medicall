#include "mainwindow.h"

MainWindow::MainWindow()
{
    // #####
    // ## Setup:
    // #####

    patient = Patient::getInstance();
    doctor = Doctor::getInstance();

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
    WelcomeView* welcomeView = new WelcomeView(this);
    stack->addWidget(welcomeView);

    connect(welcomeView,
            &WelcomeView::loginPatientButton_Event,
            this,
            &MainWindow::switchToLoginPatientView);
    connect(welcomeView,
            &WelcomeView::loginDoctorButton_Event,
            this,
            &MainWindow::switchToLoginDoctorView);
    connect(welcomeView,
            &WelcomeView::registerPatientButton_Event,
            this,
            &MainWindow::switchToPatientRegistrationView);
    connect(welcomeView,
            &WelcomeView::registerDoctorButton_Event,
            this,
            &MainWindow::switchToDoctorRegistrationView);
    connect(welcomeView,
            &WelcomeView::exitButton_Event,
            this,
            &QMainWindow::close);

    // # 1
    // # Login Patient View:
    LoginPatientView* loginPatientView = new LoginPatientView(this);
    stack->addWidget(loginPatientView);
    connect(loginPatientView,
            &LoginPatientView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);
    connect(loginPatientView,
            &LoginPatientView::loggedIn,
            this,
            &MainWindow::switchToPatientView);

    // # 2
    // # Login Doctor View:
    LoginDoctorView* loginDoctorView = new LoginDoctorView(this);
    stack->addWidget(loginDoctorView);
    connect(loginDoctorView,
            &LoginDoctorView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);
    connect(loginDoctorView,
            &LoginDoctorView::loggedIn,
            this,
            &MainWindow::switchToDoctorView);

    // # 3
    // # Patient Registration View:
    PatientRegistrationView* patientRegistrationView = new PatientRegistrationView(this);
    stack->addWidget(patientRegistrationView);
    connect(patientRegistrationView,
            &PatientRegistrationView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);
    connect(patientRegistrationView,
            &PatientRegistrationView::registered,
            patient,
            &Patient::initPatient);

    // # 4
    // # Doctor Registration View:
    DoctorRegistrationView* doctorRegistrationView = new DoctorRegistrationView(this);
    stack->addWidget(doctorRegistrationView);
    connect(doctorRegistrationView,
            &DoctorRegistrationView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);


    // # 5
    // # Patient View:
    patientView = new PatientView(this);
    stack->addWidget(patientView);
    connect(patientView,
            &PatientView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);
    connect(patientView,
            &PatientView::takeSurveyButton_Event,
            this,
            &MainWindow::switchToSurveyView);

    // # 6
    // # Doctor View:
    doctorView = new DoctorView(this);
    stack->addWidget(doctorView);
    connect(doctorView,
            &DoctorView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // # 7
    // # Survey View:
    surveyView = new SurveyView(this);
    stack->addWidget(surveyView);
    connect(surveyView,
            &SurveyView::backButton_Event,
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
    patient->initPatient(data);
    patientView->init();
    stack->setCurrentIndex(5);
}

void MainWindow::switchToDoctorView(QVariantHash data)
{
    doctor->initDoctor(data);
    doctorView->init();
    stack->setCurrentIndex(6);
}
