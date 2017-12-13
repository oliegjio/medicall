#include "Recomendation_Widget.h"

Recomendation_Widget::Recomendation_Widget(QString title, QString date, QString content,
                                           QString doctor, QString patient,
                                           QWidget* parent) : QWidget(parent)
{
    // ####
    // ## Setup:
    // ####

    this->title = title;
    this->date = date;
    this->content = content;
    this->doctor = doctor;
    this->patient = patient;

    QVBoxLayout* base_Layout = new QVBoxLayout();
    base_Layout->setAlignment(Qt::AlignTop);

    // ####
    // ## Widgets:
    // ####

    Label* title_Label = new Label(title);
    title_Label->setFont(QFont("Arial", 18));
    base_Layout->addWidget(title_Label);

    Label* date_Label = new Label(date);
    date_Label->setFont(QFont("Arial", 8));
    base_Layout->addWidget(date_Label);

    QTextEdit* content_Line = new QTextEdit(content);
    content_Line->setFont(QFont("Arial", 12));
    content_Line->setFrameStyle(QFrame::NoFrame);
    content_Line->setTextInteractionFlags(Qt::TextSelectableByMouse);
    base_Layout->addWidget(content_Line);

    // ####
    // ## Other:
    // ####

    setLayout(base_Layout);
}

Recomendation_Widget::~Recomendation_Widget() {}
