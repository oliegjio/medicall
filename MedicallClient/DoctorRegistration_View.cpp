#include "DoctorRegistration_View.h"

DoctorRegistration_View::DoctorRegistration_View(QWidget* parent) : QWidget(parent)
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
    connect(register_NetworkManager,
            &QNetworkAccessManager::finished,
            this,
            &DoctorRegistration_View::register_Finished);

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    middleLayout->addStretch(1);

    QLabel* title = new QLabel("Регистрация доктора:");
    title->setAlignment(Qt::AlignCenter);
    title->setFont(titleFont);
    layout->addWidget(title);

    layout->addLayout(middleLayout);
    middleLayout->addLayout(formLayout);

    // # Full name:
    QLabel* fullNameLabel = new QLabel("ФИО:");
    fullName_Line = new QLineEdit(this);
    formLayout->addRow(fullNameLabel, fullName_Line);

    // # Username:
    QLabel* usernameLabel = new QLabel("Логин:");
    username_Line = new QLineEdit(this);
    formLayout->addRow(usernameLabel, username_Line);

    // # E-Mail:
    QLabel* emailLabel = new QLabel("Эл-Почта:");
    email_Line = new QLineEdit(this);
    formLayout->addRow(emailLabel, email_Line);

    // # Password 1:
    QLabel* password1Label = new QLabel("Пароль:");
    password1_Line = new QLineEdit(this);
    password1_Line->setEchoMode(QLineEdit::Password);
    formLayout->addRow(password1Label, password1_Line);

    // # Password 2:
    QLabel* password2Label = new QLabel("Повторите пароль:");
    password2_Line = new QLineEdit(this);
    password2_Line->setEchoMode(QLineEdit::Password);
    formLayout->addRow(password2Label, password2_Line);

    // # Speciality:
    QLabel* specialityLabel = new QLabel("Специализация:");
    speciality_Line = new QLineEdit(this);
    formLayout->addRow(specialityLabel, speciality_Line);

    // # Phone Number:
    QLabel* phoneNumberLabel = new QLabel("Номер телефона:");
    phoneNumber_Line = new QLineEdit(this);
    formLayout->addRow(phoneNumberLabel, phoneNumber_Line);

    // # Social Networks:
    QLabel* socialNetworksLabel = new QLabel("Соц. сети:");
    socialNetworks_Line = new QLineEdit(this);
    formLayout->addRow(socialNetworksLabel, socialNetworks_Line);

    // # Back Button:
    QPushButton* backButton = new QPushButton("Назад");
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Clicked(); });

    // # Register Button:
    QPushButton* registerButton = new QPushButton("Зарегестрироваться");
    connect(registerButton,
            SIGNAL(clicked()),
            this,
            SLOT(registerButton_Clicked()));

    formLayout->addRow(backButton, registerButton);

    // #####
    // ## Other:
    // #####

    middleLayout->addStretch(1);
    layout->addStretch(3);

    setLayout(layout);
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
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QByteArray replyData = reply->readAll();
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid() || replyData.isEmpty()) return;

    QVariantHash data = NetworkManager::jsonToHash(replyData);

    emit registered_Event(data);
}
