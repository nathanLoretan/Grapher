#include "button.h"

Button::Button(QString text, QWidget *parent, int posx, int posy):
    QPushButton(text, parent)
{
    this->setGeometry(posx, posy, BTN_WIDTH, BTN_HEIGHT);

    // Design
    this->setStyleSheet(
        "QPushButton{"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0   rgb(100, 100, 100),"
        "stop: 0.2 rgb(100, 100, 100),"
        "stop: 0.4 rgb(70, 70, 70),"
        "stop: 1.0 rgb(70, 70, 70));"
        "color: white;"
        "border-radius: 3px;}"
        ""
        "QPushButton:pressed{"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0   rgb(80, 80, 80),"
        "stop: 0.3 rgb(108, 108, 108),"
        "stop: 0.7 rgb(108, 108, 108),"
        "stop: 1.0 rgb(80, 80, 80));"
        "color: white;"
        "border-radius: 3px;}"
    );
}
