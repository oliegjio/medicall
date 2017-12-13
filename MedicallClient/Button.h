#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT

public:
    Button(QString text, QWidget* parent = 0);
};

#endif // BUTTON_H
