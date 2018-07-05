#include "linetext.h"

LineText::LineText(QString text, QWidget *parent, int posx, int posy):
    QLineEdit("", parent)
{
    this->setGeometry(posx, posy, EDIT_WIDTH, EDIT_HEIGHT);

    // Design
    this->setStyleSheet("QLineEdit{"
                        "color: black;"
                        "border-radius: 3px;}");

    this->setPlaceholderText(text);
}

void LineText::sendText()
{
    emit sendText(this->text());
}
