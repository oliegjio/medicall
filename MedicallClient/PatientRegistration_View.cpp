#include "PatientRegistration_View.h"

PatientRegistration_View::PatientRegistration_View(QWidget* parent) : QWidget(parent)
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
            &PatientRegistration_View::register_Finished);

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    middleLayout->addStretch(1);

    // # Title
    QLabel* title = new QLabel("Регистрация пациента:");
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

    // # Birth Day:
    QLabel* birthDateLabel = new QLabel("Дата рождения:");
    birthDate_Line = new QDateTimeEdit(this);
    birthDate_Line->setDisplayFormat("dd.MM.yyyy");
    formLayout->addRow(birthDateLabel, birthDate_Line);

    // # Location:
    QLabel* localtionLabel = new QLabel("Место проживания:");
    location_Line = new QLineEdit(this);
    formLayout->addRow(localtionLabel, location_Line);

    // # Gender:
    QLabel* genderLabel = new QLabel("Пол:");
    gender_Line = new QComboBox(this);
    gender_Line->addItem("Мужской");
    gender_Line->addItem("Женский");
    formLayout->addRow(genderLabel, gender_Line);

    // # Weight:
    QLabel* weightLabel = new QLabel("Вес:");
    weight_Line = new QLineEdit(this);
    weight_Line->setValidator(new QDoubleValidator(0.0, 300.0, 3, this));
    formLayout->addRow(weightLabel, weight_Line);

    // # Height:
    QLabel* heightLabel = new QLabel("Рост:");
    height_Line = new QLineEdit(this);
    height_Line->setValidator(new QDoubleValidator(0.0, 300.0, 3, this));
    formLayout->addRow(heightLabel, height_Line);

    // # Blood Type:
    QLabel* bloodTypeLabel = new QLabel("Группа крови:");
    bloodType_Line = new QComboBox(this);
    bloodType_Line->addItem("0");
    bloodType_Line->addItem("A");
    bloodType_Line->addItem("B");
    bloodType_Line->addItem("AB");
    formLayout->addRow(bloodTypeLabel, bloodType_Line);

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

PatientRegistration_View::~PatientRegistration_View() {}

void PatientRegistration_View::registerButton_Clicked()
{
    QJsonObject data {
        {"username", username_Line->text()},
        {"password", password1_Line->text()},
        {"passwordRepeat", password2_Line->text()},
        {"fullName", fullName_Line->text()},
        {"birthDate", birthDate_Line->text()},
        {"email", email_Line->text()},
        {"bloodType", bloodType_Line->currentText()},
        {"height", height_Line->text()},
        {"weight", weight_Line->text()},
        {"gender", gender_Line->currentText()},
        {"location", location_Line->text()},
    };

    NetworkManager::postJson(register_NetworkManager,
                             QUrl("http://localhost:8000/register-patient/"),
                             data);
}

void PatientRegistration_View::register_Finished(QNetworkReply* reply)
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
