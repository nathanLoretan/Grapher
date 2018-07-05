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

    // QLinearGradient plotGradient;
    // plotGradient.setStart(0, 0);
    // plotGradient.setFinalStop(0, 350 * GRAPH_HEIGHT / WIN_Y);
    // plotGradient.setColorAt(0, BACKGROUND_0);
    // plotGradient.setColorAt(1, BACKGROUND_1);
    this->setBackground(BACKGROUND);



    // QLinearGradient axisRectGradient;
    // axisRectGradient.setStart(0, 0);
    // axisRectGradient.setFinalStop(0, 350);
    // axisRectGradient.setColorAt(0, QColor(80, 80, 80));
    // axisRectGradient.setColorAt(1, QColor(30, 30, 30));
    this->axisRect()->setBackground(BACKGROUND);
}
