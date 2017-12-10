#include "loginpatientview.h"

LoginPatientView::LoginPatientView(QWidget* parent) : QWidget(parent)
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
            &LoginPatientView::login_Finished);

    QFont logoFont("Arial", 75);

    int linesWidth = 400;
    int labelsWidth = 150;

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    // # Logo
    QLabel* logo = new QLabel("Medicall");
    logo->setAlignment(Qt::AlignCenter);
    logo->setFont(logoFont);
    layout->addWidget(logo);

    layout->addStretch(1);
    layout->addLayout(formLayout);

    // # Username:
    QLabel* usernameLineLabel = new QLabel("Логин:");
    usernameLineLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(usernameLineLabel, 0, 0);

    usernameLine = new QLineEdit();
    usernameLine->setMaximumWidth(linesWidth);
    formLayout->addWidget(usernameLine, 0, 1);

    // # Password:
    QLabel* passwordLineLabel = new QLabel("Пароль:");
    passwordLineLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(passwordLineLabel, 1, 0);

    passwordLine = new QLineEdit();
    passwordLine->setMaximumWidth(linesWidth);
    passwordLine->setEchoMode(QLineEdit::Password);
    formLayout->addWidget(passwordLine, 1, 1);

    // # Buttons:
    QPushButton* backButton = new QPushButton("Назад");
    formLayout->addWidget(backButton, 2, 0);
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Event(); });

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

LoginPatientView::~LoginPatientView() {}

void LoginPatientView::loginButton_Clicked()
{
    QJsonObject data {
        {"username", usernameLine->text()},
        {"password", passwordLine->text()}
    };

    NetworkManager::postJson(login_NetworkManager,
                             QUrl("http://localhost:8000/login-patient/"),
                             data);
}

void LoginPatientView::login_Finished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QByteArray replyData = reply->readAll();

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid() || replyData.isEmpty()) return;

    QVariantHash data = NetworkManager::jsonToHash(replyData);

    emit loggedIn(data);
}
