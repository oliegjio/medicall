#include "registrationview.h"

RegistrationView::RegistrationView(QWidget* parent) : QWidget(parent)
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

    network = NetworkManager::getInstance();

    QFont titleFont("Arial", 30);

    int linesWidth = 400;
    int labelsWidth = 150;

    layout->addStretch(3);

    // #####
    // ## Widgets:
    // #####

    middleLayout->addStretch(1);

    QLabel* title = new QLabel("Регистрация:");
    title->setAlignment(Qt::AlignCenter);
    title->setFont(titleFont);
    layout->addWidget(title);

    layout->addLayout(middleLayout);
    middleLayout->addLayout(formLayout);

    // # Full name:
    QLabel* fullNameLabel = new QLabel("ФИО:");
    QLineEdit* fullNameLine = new QLineEdit(this);
    formLayout->addRow(fullNameLabel, fullNameLine);

    // # Password 1:
    QLabel* password1Label = new QLabel("Пароль:");
    QLineEdit* password1Line = new QLineEdit(this);
    password1Line->setEchoMode(QLineEdit::Password);
    formLayout->addRow(password1Label, password1Line);

    // # Password 2:
    QLabel* password2Label = new QLabel("Повторите пароль:");
    QLineEdit* password2Line = new QLineEdit(this);
    password2Line->setEchoMode(QLineEdit::Password);
    formLayout->addRow(password2Label, password2Line);

    // # Birth Day:
    QLabel* birthDayLabel = new QLabel("Дата рождения:");
    QDateTimeEdit* birthDayLine = new QDateTimeEdit(this);
    birthDayLine->setDisplayFormat("dd.MM.yyyy");
    formLayout->addRow(birthDayLabel, birthDayLine);

    // # Location:
    QLabel* localtionLabel = new QLabel("Место проживания:");
    QLineEdit* locationLine = new QLineEdit(this);
    formLayout->addRow(localtionLabel, locationLine);

    // # Gender:
    QLabel* genderLabel = new QLabel("Пол:");
    QComboBox* genderLine = new QComboBox(this);
    genderLine->addItem("Мужской");
    genderLine->addItem("Женский");
    formLayout->addRow(genderLabel, genderLine);

    // # Weight:
    QLabel* weightLabel = new QLabel("Вес:");
    QLineEdit* weightLine = new QLineEdit(this);
    weightLine->setValidator(new QDoubleValidator(0.0, 300.0, 3, this));
    formLayout->addRow(weightLabel, weightLine);

    // # Height:
    QLabel* heightLabel = new QLabel("Рост:");
    QLineEdit* heightLine = new QLineEdit(this);
    heightLine->setValidator(new QDoubleValidator(0.0, 300.0, 3, this));
    formLayout->addRow(heightLabel, heightLine);

    // # Blood Type:
    QLabel* bloodTypeLabel = new QLabel("Группа крови:");
    QComboBox* bloodTypeLine = new QComboBox(this);
    bloodTypeLine->addItem("0");
    bloodTypeLine->addItem("A");
    bloodTypeLine->addItem("B");
    bloodTypeLine->addItem("AB");
    formLayout->addRow(bloodTypeLabel, bloodTypeLine);

    // # Buttons:
    QPushButton* backButton = new QPushButton("Назад");
    QPushButton* registerButton = new QPushButton("Зарегестрироваться");
    formLayout->addRow(backButton, registerButton);

    // #####
    // ## Other:
    // #####

    middleLayout->addStretch(1);
    layout->addStretch(3);

    setLayout(layout);
}

RegistrationView::~RegistrationView() {}
