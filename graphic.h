#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <QObject>

#include "style.h"
#include "qcustomplot/qcustomplot.h"

class Graphic : public QCustomPlot
{
    Q_OBJECT

public:
    Graphic(QWidget *parent, int posx, int posy);

};

#endif // GRAPHIC_H
