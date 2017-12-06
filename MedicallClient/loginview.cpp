#include "loginview.h"

LoginView::LoginView(QWidget* parent) : QWidget(parent)
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

    // # usernameLine:
    QLabel* usernameLineLabel = new QLabel("Логин:");
    usernameLineLabel->setMaximumWidth(labelsWidth);
    formLayout->addWidget(usernameLineLabel, 0, 0);

    usernameLine = new QLineEdit();
    usernameLine->setMaximumWidth(linesWidth);
    formLayout->addWidget(usernameLine, 0, 1);

    // # passwordLine:
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
    connect(backButton, SIGNAL(clicked()), this, SLOT(backClicked()));

    QPushButton* loginButton = new QPushButton("Войти");
    formLayout->addWidget(loginButton, 2, 1);
    connect(loginButton, SIGNAL(clicked()), this, SLOT(loginClicked()));

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

    QHttpPart usernameLinePart;
    usernameLinePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"usernameLine\""));
    usernameLinePart.setBody(usernameLine->text().toLatin1());

    QHttpPart passwordLinePart;
    passwordLinePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"passwordLine\""));
    passwordLinePart.setBody(passwordLine->text().toLatin1());

    multiPart->append(usernameLinePart);
    multiPart->append(passwordLinePart);

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
void LoginView::backClicked() { emit switchToWelcomeView(); }
