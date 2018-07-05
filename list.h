#ifndef LIST_H
#define LIST_H

#include <QComboBox>

#include "style.h"

class List : public QComboBox
{

public:
    List(QWidget *parent, int posx, int posy);
};

#endif // LIST_H
