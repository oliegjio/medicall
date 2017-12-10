#include "mainwindow.h"

MainWindow::MainWindow()
{
    // #####
    // ## Setup:
    // #####

    resize(QDesktopWidget().availableGeometry(this).size() * 0.6);
    setWindowTitle("Medicall");

    stack = new QStackedWidget();

    setCentralWidget(stack);

    QFont defaultFont("Arial", 15);
    setFont(defaultFont);

    Patient* patient = Patient::getInstance();
    Doctor* doctor = Doctor::getInstance();

    // #####
    // ## Stack:
    // #####

    // # 0
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

    // # 1
    LoginPatientView* loginPatientView = new LoginPatientView(this);
    stack->addWidget(loginPatientView);
    connect(loginPatientView,
            &LoginPatientView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // # 2
    LoginDoctorView* loginDoctorView = new LoginDoctorView(this);
    stack->addWidget(loginDoctorView);
    connect(loginDoctorView,
            &LoginDoctorView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // # 3
    PatientRegistrationView* patientRegistrationView = new PatientRegistrationView(this);
    stack->addWidget(patientRegistrationView);
    connect(patientRegistrationView,
            &PatientRegistrationView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // # 4
    DoctorRegistrationView* doctorRegistrationView = new DoctorRegistrationView(this);
    stack->addWidget(doctorRegistrationView);
    connect(doctorRegistrationView,
            &DoctorRegistrationView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // # 5
    patientView = new PatientView(this);
    stack->addWidget(patientView);
    connect(patientView,
            &PatientView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // # 6
    doctorView = new DoctorView(this);
    stack->addWidget(doctorView);
    connect(doctorView,
            &DoctorView::backButton_Event,
            this,
            &MainWindow::switchToWelcomeView);

    // #####
    // ## Other:
    // #####

    connect(loginPatientView,
            &LoginPatientView::loggedIn,
            patient,
            &Patient::initPatient);
    connect(loginPatientView,
            &LoginPatientView::loggedIn,
            this,
            &MainWindow::switchToPatientView);

    connect(loginDoctorView,
            &LoginDoctorView::loggedIn,
            doctor,
            &Doctor::initDoctor);
    connect(loginDoctorView,
            &LoginDoctorView::loggedIn,
            this,
            &MainWindow::switchToDoctorView);

    connect(patientRegistrationView,
            &PatientRegistrationView::registered,
            patient,
            &Patient::initPatient);

    setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow() {}

void MainWindow::switchToWelcomeView() { stack->setCurrentIndex(0); }

void MainWindow::switchToLoginPatientView() { stack->setCurrentIndex(1); }

void MainWindow::switchToLoginDoctorView() { stack->setCurrentIndex(2); }

void MainWindow::switchToPatientRegistrationView() { stack->setCurrentIndex(3); }

void MainWindow::switchToDoctorRegistrationView() { stack->setCurrentIndex(4); }

void MainWindow::switchToPatientView()
{
    patientView->init();
    stack->setCurrentIndex(5);
}

void MainWindow::switchToDoctorView()
{
    doctorView->init();
    stack->setCurrentIndex(6);
}
