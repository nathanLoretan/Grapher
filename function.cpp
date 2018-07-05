#include "function.h"

Function::Function(double *refVmin, double *refVmax, int *refNbrPoint)
{
    functionString = "y=";
    isShowable = true;

    ptrVmin = refVmin;
    ptrVmax = refVmax;
    ptrNbrPoint = refNbrPoint;

    firstFunc = NULL;
    x = NULL;
    y = NULL;

    color = Qt::cyan;
}

Function::~Function()
{
    delete x;
    delete y;
}

// GET/SET
QString Function::getFunction()
{
    return functionString;
}

void Function::setFunction(QString newFunc)
{
    functionString = newFunc;
}

bool Function::getShowable()
{
    return isShowable;
}

void Function::setShowable(bool condition)
{
    isShowable = condition;
}

double Function::getTableValueX(int index)
{
    if(x != NULL)
        return x->at(index);
    else
        return 0;
}

double Function::getTableValueY(int index)
{
    if(y != NULL)
        return y->at(index);
    else
        return 0;
}

QVector<double> Function::getTableX()
{
    return *x;
}

QVector<double> Function::getTableY()
{
    return *y;
}

QColor Function::getColor()
{
    return color;
}

void Function::setColor(QColor newColor)
{
    isShowable = true;
    color = newColor;
}

// Calcul the function
bool Function::calculFunction()
{
    QString priority;
    if(definePriority(priority))
    {
        if(firstFunc != NULL)
            delete firstFunc;
        firstFunc = priority_addSub(priority, 0);

        createTable();
    }
    else
    {
        setFunction("y=");
        return false;
    }

    return true;
}

bool Function::definePriority(QString &priority)
{
    int     priorityDegree = 0;
    priority = functionString.section("y=", 1, 1);  // Throw away y =
    priority.remove(QChar(' '), Qt::CaseInsensitive);

    for(int i = 0; i < priority.length(); i++)
    {
        if(priority.at(i).toLatin1() == '{' ||
           priority.at(i).toLatin1() == '[' ||
           priority.at(i).toLatin1() == '(')
        {
            // i++ because 2 char are adding to the string
            priority.replace(i, 1, "P" + QString::number(priorityDegree));
            priorityDegree++;
        }
        else if(priority.at(i).toLatin1() == '}' ||
                priority.at(i).toLatin1() == ']' ||
                priority.at(i).toLatin1() == ')')
        {
            priorityDegree--;
            // i++ because 2 char are adding to the string
            priority.replace(i, 1, "P" + QString::number(priorityDegree));
        }
    }

    if(priorityDegree != 0)
        return false;

    return true;
}

void Function::createTable()
{
    delete y;
    delete x;

    y = new QVector<double>(*ptrNbrPoint);
    x = new QVector<double>(*ptrNbrPoint);

    resolution = (*ptrVmax - *ptrVmin)/(*ptrNbrPoint);

    for(int i = 0; i < *ptrNbrPoint; i++)
    {
        y->replace(i, firstFunc->c());
        x->replace(i, *ptrVmin + i*resolution);
    }
}

MathFunction* Function::priority_addSub(QString priority, int priorityLevel)
{
    int i = 0;

     // Stop at the last element and not between two ()
    while(priority.section(QRegExp("(\\P" +
                    QString::number(priorityLevel) + ")"), i, i) != "" ||
          priority.section(QRegExp("(\\P" +
                    QString::number(priorityLevel) + ")"), i+1, i+1) != "" )
    {
        // x-y
        if(priority.section(QRegExp("(\\P" +
                    QString::number(priorityLevel) + ")"), i, i).contains('+'))
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf('+');

            return new Add(
                priority_addSub(priority.left(nbrChar), priorityLevel),
                priority_addSub(priority.right(priority.length()-nbrChar-1),
                priorityLevel));
        }
        // x+y
        else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), i, i).contains('-'))
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf('-');

            return new Sub(
                priority_addSub(priority.left(nbrChar), priorityLevel),
                priority_addSub(priority.right(priority.length()-nbrChar-1),
                priorityLevel));
        }
        i += 2; // Don't look inside the separation
    }
    return priority_mulDiv(priority, priorityLevel);
}

MathFunction* Function::priority_mulDiv(QString priority, int priorityLevel)
{
    int i = 0;

    while(priority.section(QRegExp("(\\P" +
                    QString::number(priorityLevel) + ")"), i, i) != "" ||
          priority.section(QRegExp("(\\P" +
                    QString::number(priorityLevel) + ")"), i+1, i+1) != "" )
    {
        //x*y
        if(priority.section(QRegExp("(\\P" +
                    QString::number(priorityLevel) + ")"), i, i).contains('*'))
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf('*');

            return new Mul(
                priority_addSub(priority.left(nbrChar), priorityLevel),
                priority_addSub(priority.right(priority.length()-nbrChar-1),
                priorityLevel));
        }
        // (...)(...) = (...)*(...)
        else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), i, i) == "" && i != 0)
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf("");

            return new Mul(
                priority_addSub(priority.left(nbrChar+1), priorityLevel),
                priority_addSub(priority.right(priority.length()-nbrChar-1),
                priorityLevel));
        }
        // x/y
        else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), i, i).contains('/'))
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf('/');

            return new Div(
                priority_addSub(priority.left(nbrChar), priorityLevel),
                priority_addSub(priority.right(priority.length()-nbrChar-1),
                priorityLevel));
        }
        i += 2; // Don't look inside the separation
    }
    return priority_pow(priority, priorityLevel);
}

MathFunction* Function::priority_pow(QString priority, int priorityLevel)
{
    int i = 0;

    while(priority.section(QRegExp("(\\P" +
                        QString::number(priorityLevel) + ")"), i, i) != "" ||
          priority.section(QRegExp("(\\P" +
                        QString::number(priorityLevel) + ")"), i+1, i+1) != "" )
    {
        //x^n
        if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), i, i).contains('^'))
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf('^');

            return new Pow(
                priority_addSub(priority.left(nbrChar), priorityLevel),
                priority_addSub(priority.right(priority.length()-nbrChar-1),
                priorityLevel));
        }
        // x*10^n
        else if(priority.section(QRegExp("(\\P" +
            QString::number(priorityLevel) + ")"), i, i).contains(QRegExp("(e)")))
        {
            int nbrChar = priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, i).lastIndexOf('e');

            // if it's not exp()
            if(priority.length() < nbrChar+3 || priority.at(nbrChar+2) != 'p')
            {
                    return new E(
                        priority_addSub(priority.left(nbrChar), priorityLevel),
                        priority_addSub(priority.right(priority.length()-nbrChar-1),
                        priorityLevel));
            }
        }
        i += 2; // Don't look inside the separation
    }
     return priority_specialFunc(priority, priorityLevel);
}

MathFunction* Function::priority_specialFunc(QString priority, int priorityLevel)
{
    // Always before a separation
    if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("sin"))

        return new Sin(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("cos"))

        return new Cos(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("tan"))

        return new Tan(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("arcsin"))

        return new ArcSin(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("arccos"))

        return new ArcCos(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("arctan"))

        return new ArcTan(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("exp"))

        return new Exp(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("ln"))

        return new Ln(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("sqrt"))

        return new Sqrt(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("abs"))

        return new Abs(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1), priorityLevel+1));

    else if(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 0, 0).contains("|"))
        return new Abs(priority_addSub(priority.section(QRegExp("(\\P" +
                QString::number(priorityLevel) + ")"), 1, 1).remove('|'),
                priorityLevel+1));

    else
        return priority_separator(priority, priorityLevel);

}

MathFunction* Function::priority_separator(QString priority, int priorityLevel)
{

    if(priority.contains("P" + QString::number(priorityLevel)))
        return priority_addSub(priority.remove("P" +
                            QString::number(priorityLevel), Qt::CaseInsensitive)
                             , priorityLevel + 1);
    else
        return priority_number(priority);

}

// Last Stage
MathFunction* Function::priority_number(QString priority)
{
    bool nbrToStr;
    double value = priority.toDouble(&nbrToStr);

    if(nbrToStr)
        return new Cst(value);

    else if(priority.contains('x'))
        return new X(ptrVmin, &resolution);

    else
        return new Cst(0);
}
