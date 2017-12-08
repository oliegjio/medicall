#include "mainwindow.h"

MainWindow::MainWindow()
{
    // #####
    // ## Setup:
    // #####

    resize(QDesktopWidget().availableGeometry(this).size() * 0.5);
    setWindowTitle("Medicall");

    stack = new QStackedWidget();

    setCentralWidget(stack);

    QFont defaultFont("Arial", 15);
    setFont(defaultFont);

    Patient* patient = new Patient(this);

    // #####
    // ## Stack:
    // #####

    // # 0
    WelcomeView* welcomeView = new WelcomeView(this);
    stack->addWidget(welcomeView);
    connect(welcomeView, &WelcomeView::switchToLoginView, this, &MainWindow::switchToLoginView);
    connect(welcomeView, &WelcomeView::switchToPatientRegistrationView, this, &MainWindow::switchToPatientRegistrationView);
    connect(welcomeView, &WelcomeView::switchToDoctorRegistrationView, this, &MainWindow::switchToDoctorRegistrationView);

    // # 1
    LoginView* loginView = new LoginView(this);
    stack->addWidget(loginView);
    connect(loginView, &LoginView::switchToWelcomeView, this, &MainWindow::switchToWelcomeView);

    // # 2
    PatientRegistrationView* patientRegistrationView = new PatientRegistrationView(this);
    stack->addWidget(patientRegistrationView);

    // #####
    // ## Other:
    // #####

    connect(loginView, &LoginView::loggedIn, patient, &Patient::getPatient);

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
