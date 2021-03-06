#include "DoctorRegistration_View.h"

DoctorRegistration_View::DoctorRegistration_View(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* base_Layout = new QVBoxLayout(this);
    base_Layout->setAlignment(Qt::AlignCenter);

    QHBoxLayout* middle_Layout = new QHBoxLayout(this);
    middle_Layout->setAlignment(Qt::AlignCenter);

    QFormLayout* form_Layout  = new QFormLayout(this);
    form_Layout->setHorizontalSpacing(30);
    form_Layout->setVerticalSpacing(10);

    register_NetworkManager = new QNetworkAccessManager;
    connect(register_NetworkManager,
            &QNetworkAccessManager::finished,
            this,
            &DoctorRegistration_View::register_Finished);

    base_Layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    middle_Layout->addStretch(1);

    Label* title_Label = new Label("Регистрация доктора:");
    title_Label->setAlignment(Qt::AlignCenter);
    title_Label->setFont(QFont("Arial", 30));
    base_Layout->addWidget(title_Label);

    base_Layout->addLayout(middle_Layout);
    middle_Layout->addLayout(form_Layout);

    // # Full name:
    Label* fullName_Label = new Label("ФИО:");
    fullName_Line = new LineEdit(this);
    form_Layout->addRow(fullName_Label, fullName_Line);

    // # Username:
    Label* username_Label = new Label("Логин:");
    username_Line = new LineEdit(this);
    form_Layout->addRow(username_Label, username_Line);

    // # E-Mail:
    Label* email_Label = new Label("Эл-Почта:");
    email_Line = new LineEdit(this);
    form_Layout->addRow(email_Label, email_Line);

    // # Password 1:
    Label* password1_Label = new Label("Пароль:");
    password1_Line = new LineEdit(this);
    password1_Line->setEchoMode(LineEdit::Password);
    form_Layout->addRow(password1_Label, password1_Line);

    // # Password 2:
    Label* password2_Label = new Label("Повторите пароль:");
    password2_Line = new LineEdit(this);
    password2_Line->setEchoMode(LineEdit::Password);
    form_Layout->addRow(password2_Label, password2_Line);

    // # Speciality:
    Label* speciality_Label = new Label("Специализация:");
    speciality_Line = new LineEdit(this);
    form_Layout->addRow(speciality_Label, speciality_Line);

    // # Phone Number:
    Label* phoneNumber_Label = new Label("Номер телефона:");
    phoneNumber_Line = new LineEdit(this);
    form_Layout->addRow(phoneNumber_Label, phoneNumber_Line);

    // # Social Networks:
    Label* socialNetworks_Label = new Label("Соц. сети:");
    socialNetworks_Line = new LineEdit(this);
    form_Layout->addRow(socialNetworks_Label, socialNetworks_Line);

    // # Back Button:
    Button* back_Button = new Button("Назад");
    connect(back_Button,
            &Button::clicked,
            [=] () { emit backButton_Clicked(); });

    // # Register Button:
    Button* register_Button = new Button("Зарегестрироваться");
    connect(register_Button,
            SIGNAL(clicked()),
            this,
            SLOT(registerButton_Clicked()));

    form_Layout->addRow(back_Button, register_Button);

    // #####
    // ## Other:
    // #####

    middle_Layout->addStretch(1);
    base_Layout->addStretch(3);

    setLayout(base_Layout);
}

DoctorRegistration_View::~DoctorRegistration_View() {}

void DoctorRegistration_View::registerButton_Clicked()
{
    QJsonObject data {
        {"username", username_Line->text()},
        {"password", password1_Line->text()},
        {"passwordRepeat", password2_Line->text()},
        {"fullName", fullName_Line->text()},
        {"email", email_Line->text()},
        {"speciality", speciality_Line->text()},
        {"phoneNumber", phoneNumber_Line->text()},
        {"socialNetworks", socialNetworks_Line->text()}
    };

    NetworkManager::postJson(register_NetworkManager,
                             QUrl("http://localhost:8000/register-doctor/"),
                             data);
}

void DoctorRegistration_View::register_Finished(QNetworkReply* reply)
{
    QVariantHash data = NetworkManager::processReply(reply);

    if(!data["status"].isValid()) return;

    emit registered_Event(data);
}
