#include "Patient_View.h"

Patient_View::Patient_View(QWidget* parent) : QWidget(parent) {}

Patient_View::~Patient_View() {}

void Patient_View::init()
{
    // ####
    // ## Setup:
    // ####

    Patient_Model* patient = Patient_Model::getInstance();

    QHBoxLayout* baseLayout = new QHBoxLayout();

    QVBoxLayout* sideBarLayout = new QVBoxLayout();
    sideBarLayout->setAlignment(Qt::AlignTop);
    baseLayout->addLayout(sideBarLayout, 1);

    QFormLayout* userInfoLayout = new QFormLayout();

    QFont userInfoFont("Arial", 15);

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOn );

    content_Layout = new QVBoxLayout();
    content_Layout->setAlignment(Qt::AlignTop);
    content_Layout->setContentsMargins(0, 0, 0, 0);

    QNetworkAccessManager* getRecomendations_NetworkManager = new QNetworkAccessManager();
    connect(getRecomendations_NetworkManager,
            &QNetworkAccessManager::finished,
            this,
            &Patient_View::getRecomendations_Finished);
    QUrl getRecomendatinos_Url("http://localhost:8000/recomendations/patient/" + patient->id);
    NetworkManager::postJsonToken(getRecomendations_NetworkManager,
                                  getRecomendatinos_Url,
                                  patient->token);

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

    // # Take Survery Button:
    QPushButton* takeSurveyButton = new QPushButton("Пройти обследование");
    sideBarLayout->addWidget(takeSurveyButton);
    connect(takeSurveyButton,
            &QPushButton::clicked,
            [=] () { emit takeSurveyButton_Clicked(); });

    // # Back Button:
    QPushButton* backButton = new QPushButton("Назад");
    sideBarLayout->addWidget(backButton);
    connect(backButton,
            &QPushButton::clicked,
            [=] () { emit backButton_Clicked(); });

    // ####
    // ## Other:
    // ####

    // # Scroll Area:
    QWidget* contentColumn = new QWidget();
    contentColumn->setLayout(content_Layout);
    scrollArea->setWidget(contentColumn);
    scrollArea->setWidgetResizable(true);
    baseLayout->addWidget(scrollArea, 3);

    setLayout(baseLayout);
}

void Patient_View::getRecomendations_Finished(QNetworkReply* reply)
{
    if (reply->error()) {
        qDebug() << reply->errorString();
        return;
    }

    QByteArray replyData = reply->readAll();

    QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (!statusCode.isValid() || replyData.isEmpty()) return;

    QVariantHash data = NetworkManager::jsonToHash(replyData);

    // # Recomendations:
    QVector<Recomendation_Widget*> recomendationWidgets;

    QVariantHash::iterator i;
    for (i = data.begin(); i != data.end(); i++)
    {
        QString title = i.value().toHash()["title"].value<QString>();
        QString date = i.value().toHash()["date"].value<QString>();
        QString content = i.value().toHash()["content"].value<QString>();
        QString doctor = i.value().toHash()["doctor"].value<QString>();
        QString patient = i.value().toHash()["patient"].value<QString>();

        Recomendation_Widget* recomendationWidget =
                new Recomendation_Widget(title, date, content, doctor, patient);

        recomendationWidgets.append(recomendationWidget);
        content_Layout->addWidget(recomendationWidget);
    }
}
