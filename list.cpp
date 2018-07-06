#include "list.h"

List::List(QWidget *parent, int posx, int posy):
    QComboBox(parent)
{
    this->setGeometry(posx, posy, LIST_WIDTH, LIST_HEIGHT);

    // Design
    this->setStyleSheet(
        "QComboBox {"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0   rgb(100, 100, 100),"
        "stop: 0.2 rgb(100, 100, 100),"
        "stop: 0.4 rgb(70, 70, 70),"
        "stop: 1.0 rgb(70, 70, 70));"
        "color: white;"
        "border-radius: 5px;"
        "}"
        "QComboBox::drop-down {"
            "border: 0px;"
        "}"
    );
}
