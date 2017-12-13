#include "Patient_View.h"

Patient_View::Patient_View(QWidget* parent) : QWidget(parent) {}

Patient_View::~Patient_View() {}

void Patient_View::init()
{
    // ####
    // ## Setup:
    // ####

    Patient_Model* patient = Patient_Model::getInstance();

    QHBoxLayout* base_Layout = new QHBoxLayout();

    QVBoxLayout* sideBar_Layout = new QVBoxLayout();
    sideBar_Layout->setAlignment(Qt::AlignTop);
    base_Layout->addLayout(sideBar_Layout, 1);

    QFormLayout* userInfo_Layout = new QFormLayout();

    QFont userInfo_Font("Arial", 15);

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
    Label* username_Label = new Label(patient->username);
    username_Label->setFont(usernameLabel_Font);
    sideBar_Layout->addWidget(username_Label);

    // # Divider:
    QWidget* line = new QWidget;
    line->setFixedHeight(2);
    line->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    line->setStyleSheet(QString("background-color: black;"));
    sideBar_Layout->addWidget(line);

    sideBar_Layout->addLayout(userInfo_Layout);

    // # E-Mail:
    Label* email_Label = new Label("E-Mail:");
    email_Label->setFont(userInfo_Font);
    Label* email_Value = new Label(patient->email);
    email_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(email_Label, email_Value);

    // # Full Name:
    Label* fullName_Label = new Label("ФИО:");
    fullName_Label->setFont(userInfo_Font);
    Label* fullName_Value = new Label(patient->fullName);
    fullName_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(fullName_Label, fullName_Value);

    // # Birth Date:
    Label* birthDate_Label = new Label("Дата рождения:");
    birthDate_Label->setFont(userInfo_Font);
    Label* birthDate_Value = new Label(patient->birthDate);
    birthDate_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(birthDate_Label, birthDate_Value);

    // # Location:
    Label* location_Label = new Label("Место проживания:");
    location_Label->setFont(userInfo_Font);
    Label* location_Value = new Label(patient->location);
    location_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(location_Label, location_Value);

    // # Weight:
    Label* weight_Label = new Label("Вес:");
    weight_Label->setFont(userInfo_Font);
    Label* weight_Value = new Label(patient->weight);
    weight_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(weight_Label, weight_Value);

    // # Height:
    Label* height_Label = new Label("Рост:");
    height_Label->setFont(userInfo_Font);
    Label* height_Value = new Label(patient->height);
    height_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(height_Label, height_Value);

    // # Blood Type:
    Label* bloodType_Label = new Label("Группа крови:");
    bloodType_Label->setFont(userInfo_Font);
    Label* bloodType_Value = new Label(patient->height);
    bloodType_Value->setFont(userInfo_Font);
    userInfo_Layout->addRow(bloodType_Label, bloodType_Value);

    sideBar_Layout->addStretch(1);

    // # Take Survery Button:
    Button* takeSurvey_Button = new Button("Пройти обследование");
    sideBar_Layout->addWidget(takeSurvey_Button);
    connect(takeSurvey_Button,
            &Button::clicked,
            [=] () { emit takeSurveyButton_Clicked(); });

    // # Back Button:
    Button* back_Button = new Button("Назад");
    sideBar_Layout->addWidget(back_Button);
    connect(back_Button,
            &Button::clicked,
            [=] () { emit backButton_Clicked(); });

    // ####
    // ## Other:
    // ####

    // # Scroll Area:
    QWidget* contentColumn = new QWidget();
    contentColumn->setLayout(content_Layout);
    scrollArea->setWidget(contentColumn);
    scrollArea->setWidgetResizable(true);
    base_Layout->addWidget(scrollArea, 3);

    setLayout(base_Layout);
}

void Patient_View::getRecomendations_Finished(QNetworkReply* reply)
{
    QVariantHash data = NetworkManager::processReply(reply);

    if (!data["status"].isValid()) return;

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
