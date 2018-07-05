#ifndef OBSERVER_H
#define OBSERVER_H

#include "style.h"

class Observer
{
public:
    virtual void notificationNew()             = 0;
    virtual void notificationSave()            = 0;
    virtual void notificationIndex()           = 0;
    virtual void notificationTable()           = 0;
    virtual void notificationGraphe()          = 0;
    virtual void notificationRemove()          = 0;
    virtual void notificatiponClearCmd()       = 0;
    virtual void notificationRedraw(int index) = 0;
};

#endif // OBSERVER_H
