#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QPalette>
#include <QString>

#include "style.h"

class Button : public QPushButton
{

public:
    Button(QString text, QWidget *parent, int posx, int posy);
};

#endif // BUTTON_H
