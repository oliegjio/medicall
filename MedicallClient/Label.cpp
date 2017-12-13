#include <Label.h>

Label::Label(QString text, QWidget* parent)
{
    setText(text);
    setFont(QFont("Arial", 17));
    setStyleSheet("color: charcoal");
}
