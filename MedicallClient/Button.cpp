#include "Button.h"

Button::Button(QString text, QWidget* parent)
{
    setText(text);
    setStyleSheet("background: white; border-color: navy; border: 2px solid lightgray; padding: 5px 10px;");
    setFont(QFont("Arial", 17));
}
