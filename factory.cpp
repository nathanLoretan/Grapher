#include "factory.h"

Factory::Factory()
{
    window      = new MainWindows();
    data        = new Model();
    manageFunc  = new ManageFunc();

    window->initRelations(manageFunc, data);
    data->initRelations(window);
    manageFunc->initRelations(data);

    window->show();
}
