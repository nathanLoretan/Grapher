#ifndef FUNCTION_H
#define FUNCTION_H

#include <QString>
#include <QStringList>
#include <QVector>
#include <QColor>
#include <stdbool.h>
using namespace std;

#include "mathfunction.h"
#include "style.h"

class Function
{
private:
    double          resolution;
    double         *ptrVmax;
    double         *ptrVmin;
    int            *ptrNbrPoint;

    bool            isShowable;

    QString         functionString;
    MathFunction*   firstFunc;

    QVector<double> *x;
    QVector<double> *y;

    QColor  color;

public:
    Function(double *refVmin, double *refVmax, int *refNbrPoint);
    ~Function();

    QString getFunction();
    void    setFunction(QString newFunc);

    bool    getShowable();
    void    setShowable(bool condition);

    double getTableValueX(int index);
    double getTableValueY(int index);

    QVector<double> getTableX();
    QVector<double> getTableY();

    QColor  getColor();
    void    setColor(QColor newColor);

    void    createTable();
    bool    calculFunction();
    bool    definePriority(QString &priority);


    MathFunction* priority_separator    (QString priority, int priorityLevel);
    MathFunction* priority_addSub       (QString priority, int priorityLevel);
    MathFunction* priority_mulDiv       (QString priority, int priorityLevel);
    MathFunction* priority_pow          (QString priority, int priorityLevel);
    MathFunction* priority_specialFunc  (QString priority, int priorityLevel);
    MathFunction* priority_number       (QString priority);
};

#endif // FUNCTION_H
