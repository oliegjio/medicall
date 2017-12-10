#include "doctorregistrationview.h"

DoctorRegistrationView::DoctorRegistrationView(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    QHBoxLayout* middleLayout = new QHBoxLayout(this);
    middleLayout->setAlignment(Qt::AlignCenter);

    QFormLayout* formLayout  = new QFormLayout(this);
    formLayout->setHorizontalSpacing(30);
    formLayout->setVerticalSpacing(10);

    QFont titleFont("Arial", 30);

    register_NetworkManager = new QNetworkAccessManager;
    connect(register_NetworkManager, &QNetworkAccessManager::finished, this, &DoctorRegistrationView::register_Finished);

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    middleLayout->addStretch(1);

    QLabel* title = new QLabel("Регистрация:");
    title->setAlignment(Qt::AlignCenter);
    title->setFont(titleFont);
    layout->addWidget(title);

    layout->addLayout(middleLayout);
    middleLayout->addLayout(formLayout);

    // # Full name:
    QLabel* fullNameLabel = new QLabel("ФИО:");
    fullNameLine = new QLineEdit(this);
    formLayout->addRow(fullNameLabel, fullNameLine);

    // # Username:
    QLabel* usernameLabel = new QLabel("Логин:");
    usernameLine = new QLineEdit(this);
    formLayout->addRow(usernameLabel, usernameLine);

    // # E-Mail:
    QLabel* emailLabel = new QLabel("Эл-Почта:");
    emailLine = new QLineEdit(this);
    formLayout->addRow(emailLabel, emailLine);

    // # Password 1:
    QLabel* password1Label = new QLabel("Пароль:");
    password1Line = new QLineEdit(this);
    password1Line->setEchoMode(QLineEdit::Password);
    formLayout->addRow(password1Label, password1Line);

    // # Password 2:
    QLabel* password2Label = new QLabel("Повторите пароль:");
    password2Line = new QLineEdit(this);
    password2Line->setEchoMode(QLineEdit::Password);
    formLayout->addRow(password2Label, password2Line);

    // # Speciality:
    QLabel* specialityLabel = new QLabel("Специализация:");
    specialityLine = new QLineEdit(this);
    formLayout->addRow(specialityLabel, specialityLine);

    // # Phone Number:
    QLabel* phoneNumberLabel = new QLabel("Номер телефона:");
    phoneNumberLine = new QLineEdit(this);
    formLayout->addRow(phoneNumberLabel, phoneNumberLine);

    // # Social Networks:
    QLabel* socialNetworksLabel = new QLabel("Соц. сети:");
    socialNetworksLine = new QLineEdit(this);
    formLayout->addRow(socialNetworksLabel, socialNetworksLine);

    // # Buttons:
    QPushButton* backButton = new QPushButton("Назад");
    connect(backButton, SIGNAL(clicked()), this, SLOT(backButton_Clicked()));

    QPushButton* registerButton = new QPushButton("Зарегестрироваться");
    connect(registerButton, SIGNAL(clicked()), this, SLOT(registerButton_Clicked()));

    formLayout->addRow(backButton, registerButton);

    // #####
    // ## Other:
    // #####

    middleLayout->addStretch(1);
    layout->addStretch(3);

    setLayout(layout);
}

DoctorRegistrationView::~DoctorRegistrationView() {}

void DoctorRegistrationView::registerButton_Clicked()
{
    QJsonObject data {
        {"username", usernameLine->text()},
        {"password", password1Line->text()},
        {"passwordRepeat", password2Line->text()},
        {"fullName", fullNameLine->text()},
        {"email", emailLine->text()},
        {"speciality", specialityLine->text()},
        {"phoneNumber", phoneNumberLine->text()},
        {"socialNetworks", socialNetworksLine->text()}
    };

    NetworkManager::postJson(register_NetworkManager, QUrl("http://localhost:8000/register-doctor/"), data);
}

void DoctorRegistrationView::backButton_Clicked() { emit backButton_Event(); }

void DoctorRegistrationView::register_Finished(QNetworkReply* reply)
{
    qDebug() << reply->readAll();
}
