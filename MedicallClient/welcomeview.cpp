#include "welcomeview.h"

WelcomeView::WelcomeView(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QFont logoFont("Arial", 75);

    int buttonsWidth = 450;

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    QLabel* logo = new QLabel("Medicall");
    logo->setAlignment(Qt::AlignCenter);
    logo->setFont(logoFont);
    layout->addWidget(logo);

    layout->addStretch(1);

    QPushButton* loginButton = new QPushButton("Войти");
    loginButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(loginButton);
    connect(loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));

    QPushButton* registerPatientButton = new QPushButton("Регистрация пациента");
    registerPatientButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerPatientButton);
    connect(registerPatientButton, SIGNAL(clicked()), this, SLOT(registerPatientButtonClicked()));

    QPushButton* registerDoctorButton = new QPushButton("Регистрация доктора");
    registerDoctorButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerDoctorButton);
    connect(registerDoctorButton, SIGNAL(clicked()), this, SLOT(registerDoctorButtonClicked()));

    // #####
    // ## Other:
    // #####

    layout->addStretch(3);

    setLayout(layout);
}

// Switch to LoginView
void WelcomeView::loginButtonClicked() { emit switchToLoginView(); }

void WelcomeView::registerPatientButtonClicked() { emit switchToPatientRegistrationView(); }

void WelcomeView::registerDoctorButtonClicked() { emit switchToDoctorRegistrationView(); }
