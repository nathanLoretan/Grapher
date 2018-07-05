#include "graphic.h"

Graphic::Graphic(QWidget *parent, int posx, int posy):
    QCustomPlot(parent)
{
    this->setGeometry(posx, posy, GRAPH_WIDTH, GRAPH_HEIGHT);
    this->setInteractions(QCP::iRangeDrag |
                          QCP::iRangeZoom |
                          QCP::iSelectPlottables);
    this->xAxis->setRange(-10, 10);
    this->yAxis->setRange(-10, 10);

    // set graph design
    this->xAxis->setBasePen(QPen(Qt::white, 1));
    this->yAxis->setBasePen(QPen(Qt::white, 1));
    this->xAxis->setTickPen(QPen(Qt::white, 1));
    this->yAxis->setTickPen(QPen(Qt::white, 1));
    this->xAxis->setSubTickPen(QPen(Qt::white, 1));
    this->yAxis->setSubTickPen(QPen(Qt::white, 1));
    this->xAxis->setTickLabelColor(Qt::white);
    this->yAxis->setTickLabelColor(Qt::white);
    
    this->setBackground(BACKGROUND);
    this->axisRect()->setBackground(BACKGROUND);
}
