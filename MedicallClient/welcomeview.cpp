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

    // # Logo:
    QLabel* logo = new QLabel("Medicall");
    logo->setAlignment(Qt::AlignCenter);
    logo->setFont(logoFont);
    layout->addWidget(logo);

    layout->addStretch(1);

    // # Login as Patient Button:
    QPushButton* loginPatientButton = new QPushButton("Войти как пациент");
    loginPatientButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(loginPatientButton);
    connect(loginPatientButton,
            &QPushButton::clicked,
            [=] () { emit loginPatientButton_Event(); });

    // # Login as Doctor Button:
    QPushButton* loginDoctorButton = new QPushButton("Войти как доктор");
    loginDoctorButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(loginDoctorButton);
    connect(loginDoctorButton,
            &QPushButton::clicked,
            [=] () { emit loginDoctorButton_Event(); });

    layout->addStretch(1);

    // # Register as Pacient:
    QPushButton* registerPatientButton = new QPushButton("Регистрация пациента");
    registerPatientButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerPatientButton);
    connect(registerPatientButton,
            &QPushButton::clicked,
            [=] () { emit registerPatientButton_Event(); });

    // # Register as Doctor:
    QPushButton* registerDoctorButton = new QPushButton("Регистрация доктора");
    registerDoctorButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerDoctorButton);
    connect(registerDoctorButton,
            &QPushButton::clicked,
            [=] () { emit registerDoctorButton_Event(); });

    // #####
    // ## Other:
    // #####

    layout->addStretch(3);

    setLayout(layout);
}
