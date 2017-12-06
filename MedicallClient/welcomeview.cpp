#include "welcomeview.h"

WelcomeView::WelcomeView(QWidget* parent) : QWidget(parent)
{
    // #####
    // ## Setup:
    // #####

    QVBoxLayout* layout = new QVBoxLayout();
    layout->setAlignment(Qt::AlignCenter);

    QFont logoFont("Arial", 75);

    int buttonsWidth = 450;

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    QLabel* logo = new QLabel("Medicall");
    logo->setAlignment(Qt::AlignCenter);
    logo->setFont(logoFont);
    layout->addWidget(logo);

    layout->addStretch(1);

    QPushButton* loginButton = new QPushButton("Войти");
    loginButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(loginButton);
    connect(loginButton, SIGNAL(clicked()), this, SLOT(loginButtonClicked()));

    QPushButton* registerButton = new QPushButton("Зарегестрироваться");
    registerButton->setMaximumWidth(buttonsWidth);
    layout->addWidget(registerButton);
    connect(registerButton, SIGNAL(clicked()), this, SLOT(registerButtonClicked()));

    // #####
    // ## Other:
    // #####

    layout->addStretch(3);

    setLayout(layout);
}

// Switch to LoginView
void WelcomeView::loginButtonClicked() { emit switchToLoginView(); }

void WelcomeView::registerButtonClicked() { emit switchToRegistrationView(); }
