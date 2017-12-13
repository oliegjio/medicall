#include "DoctorLogin_View.h"

DoctorLogin_VIew::DoctorLogin_VIew(QWidget* parent) : QWidget(parent)
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
            &DoctorLogin_VIew::login_Finished);

    int linesWidth = 400;
    int labelsWidth = 150;

    base_Layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    // # Logo:
    Label* logo_Label = new Label("Medicall");
    logo_Label->setAlignment(Qt::AlignCenter);
    logo_Label->setFont(QFont("Arial", 75));
    base_Layout->addWidget(logo_Label);

    // # Title:
    Label* title_Label = new Label("Войти доктором:");
    title_Label->setAlignment(Qt::AlignCenter);
    title_Label->setFont(QFont("Arial", 25));
    base_Layout->addWidget(title_Label);

    base_Layout->addStretch(1);
    base_Layout->addLayout(form_Layout);

    // # Username Line:
    Label* username_Label = new Label("Логин:");
    username_Label->setMaximumWidth(labelsWidth);
    form_Layout->addWidget(username_Label, 0, 0);

    username_Line = new LineEdit();
    username_Line->setMaximumWidth(linesWidth);
    form_Layout->addWidget(username_Line, 0, 1);

    // # Password Line:
    Label* password_Label = new Label("Пароль:");
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

    // # Login Button
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

DoctorLogin_VIew::~DoctorLogin_VIew() {}

void DoctorLogin_VIew::loginButton_Clicked()
{
    QJsonObject data {
        {"username", username_Line->text()},
        {"password", password_Line->text()}
    };

    NetworkManager::postJson(login_NetworkManager,
                             QUrl("http://localhost:8000/login-doctor/"),
                             data);
}

void DoctorLogin_VIew::login_Finished(QNetworkReply* reply)
{
    QVariantHash data = NetworkManager::processReply(reply);

    if (!data["status"].isValid()) return;

    emit loggedIn_Event(data);
}
