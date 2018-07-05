#ifndef MODEL_H
#define MODEL_H

#include <list>
#include <QString>
using namespace std;

#include "style.h"
#include "observer.h"
#include "function.h"

class Model
{
    friend class ManageFunc;

private:
    int funcSelected; //Index in thse QComboBox
    int nbrFunction;

    double  Vmin;
    double  Vmax;
    int     nbrPoint;

    list<Function*> funcList;

    Observer *view;

public:
    Model();

    void initRelations(Observer *newView);

    int         getFuncSelected();  //Return the func's index in the QComboBox
    int         getNbrFunction();
    Function*   getFuncReference(); //Return the func's reference in the list
    Function*   getFuncIndex(int index);
    QString     getFunction();

    void        setVmin(double newVmin);
    double      getVmin();
    void        setVmax(double newVmax);
    double      getVmax();
    void        setNbrPoint(int newNbrPoint);
    int         getNbrPoint();
};

#endif // MODEL_H
