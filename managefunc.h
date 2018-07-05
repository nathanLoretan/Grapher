#ifndef MANAGEFUNC_H
#define MANAGEFUNC_H

#include <QObject>
#include <QString>
#include <qmath.h>

#include "style.h"
#include "model.h"
#include "qcustomplot/qcustomplot.h"

const int MAX_NBR_POINT = 100;

class ManageFunc : public QObject
{
    Q_OBJECT

private:
    Model   *data;
    QRegExp *check;

public:
    ManageFunc();
    ~ManageFunc();

    void initRelations(Model *d);

    void changeColor(QString color);
    void changeNbrPoint(QString nbrPoint);
    void rescaleAxes(QString min, QString max);

public slots:
    void drawable();
    void newFunction();
    void deleteFunction();
    void selectFunc(int index);
    void selectCmd(QString cmd);
    void setMinMax(QCPRange range);
    void changeFuncName(QString newName);
};

#endif // MANAGEFUNC_H
