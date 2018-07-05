#ifndef MATHFUNCTION_H
#define MATHFUNCTION_H

#include <qmath.h>

#include "style.h"

// Virtual Function
class MathFunction
{
public:
    MathFunction(MathFunction *x)
    {
        operation1 = x;
    }

    virtual ~MathFunction()
    {
        delete operation1;
    }

    virtual double c() = 0;
    MathFunction *operation1;

};

// Base
class Cst: public MathFunction
{
private:
    double value;
public:
    Cst(double x): MathFunction(NULL)
    {
        value = x;
    }

    double c()
    {
        return value;
    }
};

class X: public MathFunction
{
private:
    double* minValue;
    double* resolution;

    double value;
    double oldMinValue;
    double oldResolution;

    void setminValue()
    {
        oldMinValue = value = *minValue;
    }

    void setResolution()
    {
        oldResolution = *resolution;
    }

public:
    X(double *minV, double *r): MathFunction(NULL)
    {
        minValue = minV;
        value = oldMinValue = *minV;

        resolution = r;
        oldResolution = *r;
    }

    double c()
    {
        if(oldMinValue != *minValue)            // If the minValue changes
            setminValue();
        if(oldResolution != *resolution)    // If the resolution changes
            setResolution();

        double buffer = value;
        value += *resolution;
        return buffer;
    }
};

class Add : public MathFunction
{
private:
    MathFunction *operation2;
public:
    Add(MathFunction *x1, MathFunction *x2):MathFunction(x1)
    {
        operation2 = x2;
    }

    ~Add()
    {
        delete operation2;
    }

    double c()
    {
       return operation1->c() + operation2->c();
    }
};

class Sub : public MathFunction
{
private:
    MathFunction *operation2;
public:
    Sub(MathFunction *x1, MathFunction *x2):MathFunction(x1)
    {
        operation2 = x2;
    }

    ~Sub()
    {
        delete operation2;
    }

    double c()
    {
        if(operation1 != NULL)
            return operation1->c() - operation2->c();
        // it's a negativ number
        else
            return - operation2->c();
    }
};

class Mul : public MathFunction
{
private:
    MathFunction *operation2;
public:
    Mul(MathFunction *x1, MathFunction *x2):MathFunction(x1)
    {
        operation2 = x2;
    }

    ~Mul()
    {
        delete operation2;
    }

    double c()
    {
       return operation1->c() * operation2->c();
    }
};

class Div : public MathFunction
{
private:
    MathFunction *operation2;
public:
    Div(MathFunction *x1, MathFunction *x2):MathFunction(x1)
    {
        operation2 = x2;
    }

    ~Div()
    {
        delete operation2;
    }

    double c()
    {
       return operation1->c() / operation2->c();
    }
};

class Pow : public MathFunction
{
private:
    MathFunction *operation2;
public:
    Pow(MathFunction *x1, MathFunction *x2):MathFunction(x1)
    {
        operation2 = x2;
    }

    ~Pow()
    {
        delete operation2;
    }

    double c()
    {
       return qPow(operation1->c(), operation2->c());
    }
};

// Trigonometric Function
class Sin : public MathFunction
{
public:
    Sin(MathFunction *x):MathFunction(x){}
    double c()
    {
       return qSin(operation1->c());
    }
};

class Cos : public MathFunction
{
public:
    Cos(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qCos(operation1->c());
    }

};

class Tan : public MathFunction
{
public:
    Tan(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qTan(operation1->c());
    }

};

class ArcSin : public MathFunction
{
public:
    ArcSin(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qAsin(operation1->c());
    }
};

class ArcCos : public MathFunction
{
public:
    ArcCos(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qAcos(operation1->c());
    }
};

class ArcTan : public MathFunction
{
public:
    ArcTan(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qAtan(operation1->c());
    }
};

// Exponential function
class Exp : public MathFunction
{
public:
    Exp(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qExp(operation1->c());
    }
};

class Ln : public MathFunction
{
public:
    Ln(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qLn(operation1->c());
    }
};

class E : public MathFunction
{
private:
    MathFunction *operation2;
public:
    E(MathFunction *x1, MathFunction *x2):MathFunction(x1)
    {
        operation2 = x2;
    }

    ~E()
    {
        delete operation2;
    }

    double c()
    {
        return operation1->c()*qPow(10, operation2->c());
    }
};

class Sqrt : public MathFunction
{
public:
    Sqrt(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qSqrt(operation1->c());
    }
};

// Other
class Abs : public MathFunction
{
public:
    Abs(MathFunction *x):MathFunction(x){}
    double c()
    {
        return qAbs(operation1->c());
    }
};

#endif // MATHFUNCTION_H
