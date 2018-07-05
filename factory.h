#ifndef FACTORY_H
#define FACTORY_H

#include "mainWindows.h"
#include "model.h"
#include "managefunc.h"
#include "style.h"

class Factory
{
private:
    Model       *data;
    MainWindows *window;
    ManageFunc  *manageFunc;

public:
    Factory();
};

#endif // FACTORY_H
