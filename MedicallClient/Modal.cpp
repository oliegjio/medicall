#include "Modal.h"

void Modal::message(QString message)
{
    QMessageBox(QMessageBox::NoIcon, "Сообщение", message).exec();
}
