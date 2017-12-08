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

    // #####
    // ## Stack:
    // #####

    // # 0
    WelcomeView* welcomeView = new WelcomeView(this);
    stack->addWidget(welcomeView);
    connect(welcomeView, &WelcomeView::loginButton_Event, this, &MainWindow::switchToLoginView);
    connect(welcomeView, &WelcomeView::registerPatientButton_Event, this, &MainWindow::switchToPatientRegistrationView);
    connect(welcomeView, &WelcomeView::registerDoctorButton_Event, this, &MainWindow::switchToDoctorRegistrationView);

    // # 1
    LoginView* loginView = new LoginView(this);
    stack->addWidget(loginView);
    connect(loginView, &LoginView::backButton_Event, this, &MainWindow::switchToWelcomeView);

    // # 2
    PatientRegistrationView* patientRegistrationView = new PatientRegistrationView(this);
    stack->addWidget(patientRegistrationView);
    connect(patientRegistrationView, &PatientRegistrationView::backButton_Event, this, &MainWindow::switchToWelcomeView);

    // # 3
    DoctorRegistrationView* doctorRegistrationView = new DoctorRegistrationView(this);
    stack->addWidget(doctorRegistrationView);

    // # 4
    patientView = new PatientView(this);
    stack->addWidget(patientView);
    connect(patientView, &PatientView::backButton_Event, this, &MainWindow::switchToWelcomeView);

    // #####
    // ## Other:
    // #####

    connect(loginView, &LoginView::loggedIn, patient, &Patient::initPatient);
    connect(loginView, &LoginView::loggedIn, this, &MainWindow::switchToPatientView);

    connect(patientRegistrationView, &PatientRegistrationView::registered, patient, &Patient::initPatient);

    setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow() {}

void MainWindow::switchToWelcomeView()
{
    stack->setCurrentIndex(0);
}

void MainWindow::switchToLoginView()
{
    stack->setCurrentIndex(1);
}

void MainWindow::switchToPatientRegistrationView()
{
    stack->setCurrentIndex(2);
}

void MainWindow::switchToDoctorRegistrationView()
{
    stack->setCurrentIndex(3);
}

void MainWindow::switchToPatientView()
{
    patientView->init();
    stack->setCurrentIndex(4);
}
