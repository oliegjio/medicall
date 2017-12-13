#include "PatientLogin_View.h"

PatientLogin_View::PatientLogin_View(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* base_Layout = new QVBoxLayout();
    base_Layout->setAlignment(Qt::AlignCenter);

    QGridLayout* form_Layout  = new QGridLayout();
    form_Layout->setAlignment(Qt::AlignCenter);

    login_NetworkManager = new QNetworkAccessManager();
    connect(login_NetworkManager,
            &QNetworkAccessManager::finished,
            this,
            &PatientLogin_View::login_Finished);

    int linesWidth = 400;
    int labelsWidth = 150;

    base_Layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    // # Logo:
    QLabel* logo_Label = new QLabel("Medicall");
    logo_Label->setAlignment(Qt::AlignCenter);
    logo_Label->setFont(QFont("Arial", 75));
    base_Layout->addWidget(logo_Label);

    // # Title:
    QLabel* title_Label = new QLabel("Войти пациентом:");
    title_Label->setAlignment(Qt::AlignCenter);
    title_Label->setFont(QFont("Arial", 25));
    base_Layout->addWidget(title_Label);

    base_Layout->addStretch(1);
    base_Layout->addLayout(form_Layout);

    // # Username Line:
    QLabel* username_Label = new QLabel("Логин:");
    username_Label->setMaximumWidth(labelsWidth);
    form_Layout->addWidget(username_Label, 0, 0);

    username_Line = new LineEdit();
    username_Line->setMaximumWidth(linesWidth);
    form_Layout->addWidget(username_Line, 0, 1);

    // # Password Line:
    QLabel* password_Label = new QLabel("Пароль:");
    password_Label->setMaximumWidth(labelsWidth);
    form_Layout->addWidget(password_Label, 1, 0);

    password_Line = new LineEdit();
    password_Line->setMaximumWidth(linesWidth);
    password_Line->setEchoMode(LineEdit::Password);
    form_Layout->addWidget(password_Line, 1, 1);

    // # Back Button:
    Button* back_Button = new Button("Назад");
    form_Layout->addWidget(back_Button, 2, 0);
    connect(back_Button,
            &Button::clicked,
            [=] () { emit backButton_Clicked(); });

    // # Login Button:
    Button* login_Button = new Button("Войти");
    form_Layout->addWidget(login_Button, 2, 1);
    connect(login_Button,
            SIGNAL(clicked()),
            this,
            SLOT(loginButton_Clicked()));
    // #####
    // ## Other:
    // #####

    base_Layout->addStretch(3);

    setLayout(base_Layout);
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
    QVariantHash data = NetworkManager::processReply(reply);

    if (!data["status"].isValid())
    {
        if (data["error"] == NetworkManager::ERR_SERVER)
        {
            Modal::message("Внутренняя ошибка!");
        }
        else
        {
            Modal::message("Неверное имя пользователя или пароль!");
        }
        return;
    }

    emit loggedIn_Event(data);
}
