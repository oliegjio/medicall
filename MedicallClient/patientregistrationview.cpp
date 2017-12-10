#include "patientregistrationview.h"

PatientRegistrationView::PatientRegistrationView(QWidget* parent) : QWidget(parent)
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
            &PatientRegistrationView::register_Finished);

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    middleLayout->addStretch(1);

    // # Title
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

    // # Birth Day:
    QLabel* birthDateLabel = new QLabel("Дата рождения:");
    birthDateLine = new QDateTimeEdit(this);
    birthDateLine->setDisplayFormat("dd.MM.yyyy");
    formLayout->addRow(birthDateLabel, birthDateLine);

    // # Location:
    QLabel* localtionLabel = new QLabel("Место проживания:");
    locationLine = new QLineEdit(this);
    formLayout->addRow(localtionLabel, locationLine);

    // # Gender:
    QLabel* genderLabel = new QLabel("Пол:");
    genderLine = new QComboBox(this);
    genderLine->addItem("Мужской");
    genderLine->addItem("Женский");
    formLayout->addRow(genderLabel, genderLine);

    // # Weight:
    QLabel* weightLabel = new QLabel("Вес:");
    weightLine = new QLineEdit(this);
    weightLine->setValidator(new QDoubleValidator(0.0, 300.0, 3, this));
    formLayout->addRow(weightLabel, weightLine);

    // # Height:
    QLabel* heightLabel = new QLabel("Рост:");
    heightLine = new QLineEdit(this);
    heightLine->setValidator(new QDoubleValidator(0.0, 300.0, 3, this));
    formLayout->addRow(heightLabel, heightLine);

    // # Blood Type:
    QLabel* bloodTypeLabel = new QLabel("Группа крови:");
    bloodTypeLine = new QComboBox(this);
    bloodTypeLine->addItem("0");
    bloodTypeLine->addItem("A");
    bloodTypeLine->addItem("B");
    bloodTypeLine->addItem("AB");
    formLayout->addRow(bloodTypeLabel, bloodTypeLine);

    // # Buttons:
    QPushButton* backButton = new QPushButton("Назад");
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Event(); });

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

PatientRegistrationView::~PatientRegistrationView() {}

void PatientRegistrationView::registerButton_Clicked()
{
    QJsonObject data {
        {"username", usernameLine->text()},
        {"password", password1Line->text()},
        {"passwordRepeat", password2Line->text()},
        {"fullName", fullNameLine->text()},
        {"birthDate", birthDateLine->text()},
        {"email", emailLine->text()},
        {"bloodType", bloodTypeLine->currentText()},
        {"height", heightLine->text()},
        {"weight", weightLine->text()},
        {"gender", genderLine->currentText()},
        {"location", locationLine->text()},
    };

    NetworkManager::postJson(register_NetworkManager,
                             QUrl("http://localhost:8000/register-patient/"),
                             data);
}

void PatientRegistrationView::register_Finished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QByteArray replyData = reply->readAll();
    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid() || replyData.isEmpty()) return;

    QVariantHash data = NetworkManager::jsonToHash(replyData);

    emit registered(data);
}
