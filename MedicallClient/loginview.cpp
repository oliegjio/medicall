#include "loginview.h"

LoginView::LoginView()
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QGridLayout* formLayout  = new QGridLayout();
    formLayout->setAlignment(Qt::AlignCenter);

    QFont logoFont("Arial", 75);

    network = NetworkManager::getInstance();

    int linesWidth = 400;
    int labelsWidth = 150;

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    QLabel* logo = new QLabel("Medicall");
    logo->setAlignment(Qt::AlignCenter);
    logo->setFont(logoFont);
    layout->addWidget(logo);

    layout->addStretch(1);
    layout->addLayout(formLayout);

    // # Username:
    QLabel* usernameLabel = new QLabel("Логин:");
    usernameLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(usernameLabel, 0, 0);

    username = new QLineEdit();
    username->setMaximumWidth(linesWidth);
    formLayout->addWidget(username, 0, 1);

    // # Password:
    QLabel* passwordLabel = new QLabel("Пароль:");
    passwordLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(passwordLabel, 1, 0);

    password = new QLineEdit();
    password->setMaximumWidth(linesWidth);
    password->setEchoMode(QLineEdit::Password);
    formLayout->addWidget(password, 1, 1);

    // # Buttons:
    QPushButton* back = new QPushButton("Назад");
    formLayout->addWidget(back, 2, 0);
    connect(back, SIGNAL(clicked()), this, SLOT(backClicked()));

    QPushButton* login = new QPushButton("Войти");
    formLayout->addWidget(login, 2, 1);
    connect(login, SIGNAL(clicked(bool)), this, SLOT(loginClicked()));

    // #####
    // ## Other:
    // #####

    layout->addStretch(3);

    setLayout(layout);
}

LoginView::~LoginView() {}

void LoginView::loginClicked()
{
    // #####
    // ## Data:
    // #####

    QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

    QHttpPart usernamePart;
    usernamePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"username\""));
    usernamePart.setBody(username->text().toLatin1());

    QHttpPart passwordPart;
    passwordPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"password\""));
    passwordPart.setBody(password->text().toLatin1());

    multiPart->append(usernamePart);
    multiPart->append(passwordPart);

    // #####
    // ## Request:
    // #####

    QUrl url("https://google.ru/");
    QNetworkRequest request(url);
    network->post(request, multiPart);

    connect(network, &QNetworkAccessManager::finished, this, [=](QNetworkReply *reply) -> void {
        if (reply->error()) {
            qDebug() << reply->errorString();
            return;
        }

        QString data = reply->readAll();

        qDebug() << data;
    });
}

// Switch to WelcomeView
void LoginView::backClicked() { emit switchView(0); }
