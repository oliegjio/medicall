#include "Welcome_View.h"

Welcome_View::Welcome_View(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* base_Layout = new QVBoxLayout();
    base_Layout->setAlignment(Qt::AlignCenter);

    int buttonsWidth = 450;

    base_Layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    // # Logo:
    QLabel* logo_Label = new QLabel("Medicall");
    logo_Label->setAlignment(Qt::AlignCenter);
    logo_Label->setFont(QFont("Arial", 75));
    base_Layout->addWidget(logo_Label);

    base_Layout->addStretch(1);

    // # Login as Patient Button:
    QPushButton* patientLogin_Button = new QPushButton("Войти как пациент");
    patientLogin_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(patientLogin_Button);
    connect(patientLogin_Button,
            &QPushButton::clicked,
            [=] () { emit patientLoginButton_Clicked(); });

    // # Login as Doctor Button:
    QPushButton* doctorLogin_Button = new QPushButton("Войти как доктор");
    doctorLogin_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(doctorLogin_Button);
    connect(doctorLogin_Button,
            &QPushButton::clicked,
            [=] () { emit doctorLoginButton_Clicked(); });

    base_Layout->addStretch(1);

    // # Register as Pacient:
    QPushButton* patientRegistration_Button = new QPushButton("Регистрация пациента");
    patientRegistration_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(patientRegistration_Button);
    connect(patientRegistration_Button,
            &QPushButton::clicked,
            [=] () { emit patientLoginButton_Clicked(); });

    // # Register as Doctor:
    QPushButton* doctorRegistration_Button = new QPushButton("Регистрация доктора");
    doctorRegistration_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(doctorRegistration_Button);
    connect(doctorRegistration_Button,
            &QPushButton::clicked,
            [=] () { emit doctorRegisterButton_Clicked(); });

    base_Layout->addStretch(1);

    // # Exit Button:
    QPushButton* exit_Button = new QPushButton("Выйти");
    exit_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(exit_Button);
    connect(exit_Button,
            &QPushButton::clicked,
            [=] () { emit exitButton_Clicked(); });

    // #####
    // ## Other:
    // #####

    base_Layout->addStretch(3);

    setLayout(base_Layout);
}
