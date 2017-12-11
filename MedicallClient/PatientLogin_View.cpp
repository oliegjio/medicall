#include "PatientLogin_View.h"

PatientLogin_View::PatientLogin_View(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QGridLayout* formLayout  = new QGridLayout();
    formLayout->setAlignment(Qt::AlignCenter);

    login_NetworkManager = new QNetworkAccessManager();
    connect(login_NetworkManager,
            &QNetworkAccessManager::finished,
            this,
            &PatientLogin_View::login_Finished);

    int linesWidth = 400;
    int labelsWidth = 150;

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    // # Logo:
    QLabel* logo = new QLabel("Medicall");
    logo->setAlignment(Qt::AlignCenter);
    logo->setFont(QFont("Arial", 75));
    layout->addWidget(logo);

    // # Title:
    QLabel* titleLabel = new QLabel("Войти пациентом:");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setFont(QFont("Arial", 25));
    layout->addWidget(titleLabel);

    layout->addStretch(1);
    layout->addLayout(formLayout);

    // # Username Line:
    QLabel* usernameLineLabel = new QLabel("Логин:");
    usernameLineLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(usernameLineLabel, 0, 0);

    username_Line = new QLineEdit();
    username_Line->setMaximumWidth(linesWidth);
    formLayout->addWidget(username_Line, 0, 1);

    // # Password Line:
    QLabel* passwordLineLabel = new QLabel("Пароль:");
    passwordLineLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(passwordLineLabel, 1, 0);

    password_Line = new QLineEdit();
    password_Line->setMaximumWidth(linesWidth);
    password_Line->setEchoMode(QLineEdit::Password);
    formLayout->addWidget(password_Line, 1, 1);

    // # Back Button:
    QPushButton* backButton = new QPushButton("Назад");
    formLayout->addWidget(backButton, 2, 0);
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Clicked(); });

    // # Login Button:
    QPushButton* loginButton = new QPushButton("Войти");
    formLayout->addWidget(loginButton, 2, 1);
    connect(loginButton,
            SIGNAL(clicked()),
            this,
            SLOT(loginButton_Clicked()));
    // #####
    // ## Other:
    // #####

    layout->addStretch(3);

    setLayout(layout);
}

PatientLogin_View::~PatientLogin_View() {}

void PatientLogin_View::loginButton_Clicked()
{
    QJsonObject data {
        {"username", username_Line->text()},
        {"password", password_Line->text()}
    };

    NetworkManager::postJson(login_NetworkManager,
                             QUrl("http://localhost:8000/login-patient/"),
                             data);
}

void PatientLogin_View::login_Finished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QByteArray replyData = reply->readAll();

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid() || replyData.isEmpty()) return;

    QVariantHash data = NetworkManager::jsonToHash(replyData);

    emit loggedIn_Event(data);
}
