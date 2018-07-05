#include "model.h"

Model::Model()
{
    Vmin = -10;
    Vmax = 10;
    nbrPoint = 50;
}

void Model::initRelations(Observer *newView)
{
    view = newView;
}

// GET/SET
Function* Model::getFuncReference()
{
    list<Function*>::iterator it = funcList.begin();
    for(int i = 0; i < funcSelected; i++)
    {
        it++;
    }
    return *it;
}

Function* Model::getFuncIndex(int index)
{
    list<Function*>::iterator it = funcList.begin();
    for(int i = 0; i < index; i++)
    {
        it++;
    }
    return *it;
}


int Model::getNbrFunction()
{
    return nbrFunction;
}

int Model::getFuncSelected()
{
    return funcSelected;
}

QString Model::getFunction()
{
    return (this->getFuncReference())->getFunction();
}

void Model::setVmin(double newVmin)
{
    Vmin = newVmin;
}

double Model::getVmin()
{
    return Vmin;
}

void Model::setVmax(double newVmax)
{
    Vmax = newVmax;
}

double Model::getVmax()
{
    return Vmax;
}

void Model::setNbrPoint(int newNbrPoint)
{
    nbrPoint = newNbrPoint;
}

int Model::getNbrPoint()
{
    return nbrPoint;
}
