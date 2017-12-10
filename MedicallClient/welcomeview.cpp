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

    QPushButton* loginPatientButton = new QPushButton("Войти как пациент");
    loginPatientButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(loginPatientButton);
    connect(loginPatientButton, SIGNAL(clicked()), this, SLOT(loginPatientButton_Clicked()));

    QPushButton* loginDoctorButton = new QPushButton("Войти как доктор");
    loginDoctorButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(loginDoctorButton);
    connect(loginDoctorButton, SIGNAL(clicked()), this, SLOT(loginDoctorButton_Clicked()));

    layout->addStretch(1);

    QPushButton* registerPatientButton = new QPushButton("Регистрация пациента");
    registerPatientButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerPatientButton);
    connect(registerPatientButton, SIGNAL(clicked()), this, SLOT(registerPatientButton_Clicked()));

    QPushButton* registerDoctorButton = new QPushButton("Регистрация доктора");
    registerDoctorButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerDoctorButton);
    connect(registerDoctorButton, SIGNAL(clicked()), this, SLOT(registerDoctorButton_Clicked()));

    // #####
    // ## Other:
    // #####

    layout->addStretch(3);

    setLayout(layout);
}

void WelcomeView::loginPatientButton_Clicked() { emit loginPatientButton_Event(); }

void WelcomeView::loginDoctorButton_Clicked() { emit loginDoctorButton_Event(); }

void WelcomeView::registerPatientButton_Clicked() { emit registerPatientButton_Event(); }

void WelcomeView::registerDoctorButton_Clicked() { emit registerDoctorButton_Event(); }
