#include "linetext.h"

LineText::LineText(QString text, QWidget *parent, int posx, int posy):
    QLineEdit(text, parent)
{
    this->setGeometry(posx, posy, EDIT_WIDTH, EDIT_HEIGHT);

    // Design
    this->setStyleSheet("QLineEdit{"
                        "color: rgb(150, 150, 150);"
                        "border-radius: 3px;}");
}

void LineText::sendText()
{
    emit sendText(this->text());
}
