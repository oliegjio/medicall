#include "patientview.h"

PatientView::PatientView(QWidget* parent) : QWidget(parent) {}

PatientView::~PatientView() {}

void PatientView::init()
{
    // ####
    // ## Setup:
    // ####

    Patient* patient = Patient::getInstance();

    QHBoxLayout* baseLayout = new QHBoxLayout();

    QVBoxLayout* sideBarLayout = new QVBoxLayout();
    sideBarLayout->setAlignment(Qt::AlignTop);
    baseLayout->addLayout(sideBarLayout, 1);

    QFormLayout* userInfoLayout = new QFormLayout();

    QFont userInfoFont("Arial", 15);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );

    QVBoxLayout* contentLayout = new QVBoxLayout();
    contentLayout->setContentsMargins(0, 0, 0, 0);

    // ####
    // ## Sidebar Widgets:
    // ####

    // # Username Title:
    QFont usernameLabel_Font("Airal", 35);
    QLabel* usernameLabel = new QLabel(patient->username);
    usernameLabel->setFont(usernameLabel_Font);
    sideBarLayout->addWidget(usernameLabel);

    // # Divider:
    QWidget* line = new QWidget;
    line->setFixedHeight(2);
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    line->setStyleSheet(QString("background-color: black;"));
    sideBarLayout->addWidget(line);

    sideBarLayout->addLayout(userInfoLayout);

    // # E-Mail:
    QLabel* emailLabel = new QLabel("E-Mail:");
    emailLabel->setFont(userInfoFont);
    QLabel* emailValue = new QLabel(patient->email);
    emailValue->setFont(userInfoFont);
    userInfoLayout->addRow(emailLabel, emailValue);

    // # Full Name:
    QLabel* fullNameLabel = new QLabel("ФИО:");
    fullNameLabel->setFont(userInfoFont);
    QLabel* fullNameValue = new QLabel(patient->fullName);
    fullNameValue->setFont(userInfoFont);
    userInfoLayout->addRow(fullNameLabel, fullNameValue);

    // # Birth Date:
    QLabel* birthDateLabel = new QLabel("Дата рождения:");
    birthDateLabel->setFont(userInfoFont);
    QLabel* birthDateValue = new QLabel(patient->birthDate);
    birthDateValue->setFont(userInfoFont);
    userInfoLayout->addRow(birthDateLabel, birthDateValue);

    // # Location:
    QLabel* locationLabel = new QLabel("Место проживания:");
    locationLabel->setFont(userInfoFont);
    QLabel* locationValue = new QLabel(patient->location);
    locationValue->setFont(userInfoFont);
    userInfoLayout->addRow(locationLabel, locationValue);

    // # Weight:
    QLabel* weightLabel = new QLabel("Вес:");
    weightLabel->setFont(userInfoFont);
    QLabel* weightValue = new QLabel(patient->weight);
    weightValue->setFont(userInfoFont);
    userInfoLayout->addRow(weightLabel, weightValue);

    // # Height:
    QLabel* heightLabel = new QLabel("Рост:");
    heightLabel->setFont(userInfoFont);
    QLabel* heightValue = new QLabel(patient->height);
    heightValue->setFont(userInfoFont);
    userInfoLayout->addRow(heightLabel, heightValue);

    // # Blood Type:
    QLabel* bloodTypeLabel = new QLabel("Группа крови:");
    bloodTypeLabel->setFont(userInfoFont);
    QLabel* bloodTypeValue = new QLabel(patient->height);
    bloodTypeValue->setFont(userInfoFont);
    userInfoLayout->addRow(bloodTypeLabel, bloodTypeValue);

    sideBarLayout->addStretch(1);

    // # Back Button:
    QPushButton* backButton = new QPushButton("Назад");
    sideBarLayout->addWidget(backButton);
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Event(); });

    // # Recomendations:
    QVector<RecomendationWidget*> recomendations;
    for (int i = 0; i < 5; i++)
    {
        RecomendationWidget* recomendation = new RecomendationWidget();
        recomendations.append(recomendation);
        contentLayout->addWidget(recomendation);
    }

    // ####
    // ## Other:
    // ####

    // # Scroll Area:
    QWidget* contentColumn = new QWidget();
    contentColumn->setLayout(contentLayout);
    scrollArea->setWidget(contentColumn);
    scrollArea->setWidgetResizable(true);
    baseLayout->addWidget(scrollArea, 3);

    setLayout(baseLayout);
}
