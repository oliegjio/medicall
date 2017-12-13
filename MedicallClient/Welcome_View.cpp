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
    Label* logo_Label = new Label("Medicall");
    logo_Label->setAlignment(Qt::AlignCenter);
    logo_Label->setFont(QFont("Arial", 75));
    base_Layout->addWidget(logo_Label);

    base_Layout->addStretch(1);

    // # Login as Patient Button:
    Button* patientLogin_Button = new Button("Войти как пациент");
    patientLogin_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(patientLogin_Button);
    connect(patientLogin_Button,
            &Button::clicked,
            [=] () { emit patientLoginButton_Clicked(); });

    // # Login as Doctor Button:
    Button* doctorLogin_Button = new Button("Войти как доктор");
    doctorLogin_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(doctorLogin_Button);
    connect(doctorLogin_Button,
            &Button::clicked,
            [=] () { emit doctorLoginButton_Clicked(); });

    base_Layout->addStretch(1);

    // # Register as Pacient:
    Button* patientRegistration_Button = new Button("Регистрация пациента");
    patientRegistration_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(patientRegistration_Button);
    connect(patientRegistration_Button,
            &Button::clicked,
            [=] () { emit patientRegisterButton_Clicked(); });

    // # Register as Doctor:
    Button* doctorRegistration_Button = new Button("Регистрация доктора");
    doctorRegistration_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(doctorRegistration_Button);
    connect(doctorRegistration_Button,
            &Button::clicked,
            [=] () { emit doctorRegisterButton_Clicked(); });

    base_Layout->addStretch(1);

    // # Exit Button:
    Button* exit_Button = new Button("Выйти");
    exit_Button->setMaximumWidth(buttonsWidth);
    base_Layout->addWidget(exit_Button);
    connect(exit_Button,
            &Button::clicked,
            [=] () { emit exitButton_Clicked(); });

    // #####
    // ## Other:
    // #####

    base_Layout->addStretch(3);

    setLayout(base_Layout);
}
