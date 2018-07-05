#include "managefunc.h"

ManageFunc::ManageFunc()
{
    check = new QRegExp(
        "(\\+)|(\\-)|(\\*)|(\\/)|(\\^)|(\\=)|"
        "(sin)|(cos)|(tan)|"
        "(arcsin)|(arccos)|(arctan)|"
        "(exp)|(ln)|(e)|(sqrt)|(abs)|"
        "(0)|(1)|(2)|(3)|(4)|(5)|(6)|(7)|(8)|(9)|"
        "(y)|(x)|(\\))|(\\()|(\\[)|(\\])|(\\{)|(\\})|(\\|)|(\\.)");

}

ManageFunc::~ManageFunc()
{
    delete check;
}

void ManageFunc::initRelations(Model *d)
{
    data = d;
    data->nbrFunction = 0;

    this->newFunction(); // create the first function
}

void ManageFunc::changeColor(QString color)
{
    if(color.compare("green") == 0)
        data->getFuncReference()->setColor(Qt::green);
    else if(color.compare("blue") == 0)
        data->getFuncReference()->setColor(Qt::blue);
    else if(color.compare("red") == 0)
        data->getFuncReference()->setColor(Qt::red);
    else if(color.compare("black") == 0)
        data->getFuncReference()->setColor(Qt::black);
    else if(color.compare("darkblue") == 0)
        data->getFuncReference()->setColor(Qt::darkBlue);
    else if(color.compare("darkred") == 0)
        data->getFuncReference()->setColor(Qt::darkRed);
    else if(color.compare("darkgreen") == 0)
        data->getFuncReference()->setColor(Qt::darkGreen);
    else if(color.compare("cyan") == 0)
        data->getFuncReference()->setColor(Qt::cyan);
    else if(color.compare("magenta") == 0)
        data->getFuncReference()->setColor(Qt::magenta);
    else if(color.compare("yellow") == 0)
        data->getFuncReference()->setColor(Qt::yellow);
    else if(color.compare("gray") == 0)
        data->getFuncReference()->setColor(Qt::gray);

    data->view->notificationGraphe();
}

void ManageFunc::changeNbrPoint(QString nbrPoint)
{
    bool nbrToStr;
    double value = nbrPoint.toInt(&nbrToStr);

    if(nbrToStr)//&& value <= MAX_NBR_POINT)
    {
        data->setNbrPoint(value);
        // Change step by step for not always recalcul the tables
        if(data->getFuncIndex(0)->getFunction().compare("y=") > 0)
        {
            // Recalcul all table
            for (std::list<Function*>::iterator it = data->funcList.begin(); it != data->funcList.end(); it++)
                (*it)->createTable();

            // Redraw all graph
            for(int i = 0; i < data->nbrFunction; i++)
                data->view->notificationRedraw(i);

            // Change table
            data->view->notificationTable();
        }
    }
}

void ManageFunc::rescaleAxes(QString min, QString max)
{
    bool nbrToStrMin;
    bool nbrToStrMax;
    double newVmin = min.toDouble(&nbrToStrMin);
    double newVmax = max.toDouble(&nbrToStrMax);

    if(nbrToStrMin && nbrToStrMin)
    {
        data->setVmax(newVmin);
        data->setVmin(newVmax);

        // Change step by step for not always recalcul the tables
        if(data->getFuncIndex(0)->getFunction().compare("y=") > 0)
        {
            // Recalcul all table
            for (std::list<Function*>::iterator it = data->funcList.begin(); it != data->funcList.end(); it++)
                (*it)->createTable();

            // Redraw all graph
            for(int i = 0; i < data->nbrFunction; i++)
                data->view->notificationRedraw(i);

            // Change table
            data->view->notificationTable();
            data->view->notificationGraphe(); // rescale
        }
    }
}

// SLOTS
void ManageFunc::changeFuncName(QString newName)
{
    // Control if the function given is correct
    QString checkString = newName.toLower().remove(' ');
    if(checkString.remove(' ').startsWith("y=") && checkString.remove(' ').compare("y=") > 0
       && checkString.replace(*check, "?").remove('?') == "")
    {
        data->getFuncReference()->setFunction(newName);
        if(data->getFuncReference()->calculFunction())
        {
            // Notification
            data->view->notificationSave();
            data->view->notificationTable();
        }
        else // if not valid, rewrite the last function
            // Notification
            data->view->notificationIndex();

    }
    else // if not valid, rewrite the last function
        // Notification
        data->view->notificationIndex();

}

void ManageFunc::newFunction()
{
    // If it's the first function created
    if(data->nbrFunction == 0)
    {
        // Create the first function
        data->funcList.push_back(new Function(&(data->Vmin), &(data->Vmax),&(data->nbrPoint)));

        data->funcSelected = data->nbrFunction;
        data->nbrFunction++;

        // Notification
        data->view->notificationNew();
    }
    // Create new Function only if the last is define
    else if(data->getFuncReference()->getFunction().remove(' ').compare("y=") > 0)
    {
        data->funcList.push_back(new Function(&(data->Vmin), &(data->Vmax), &(data->nbrPoint)));

        data->funcSelected = data->nbrFunction;
        data->nbrFunction++;

        // Notification
        data->view->notificationNew();
    }
}

void ManageFunc::deleteFunction()
{
    // Can't remove when you have only one function
    if(data->nbrFunction > 1)
    {
        // Erase in the data
        data->funcList.remove(data->getFuncReference());

        data->nbrFunction--;

        // Notification
        data->view->notificationRemove();
        data->view->notificationTable();
    }
}

void ManageFunc::selectFunc(int index)
{
    data->funcSelected = index;

    // Notification
    data->view->notificationIndex();
    data->view->notificationTable();
}

void ManageFunc::drawable()
{
    if(data->getFuncReference()->getFunction().remove(' ').compare("y=") > 0)
    {
        data->getFuncReference()->setShowable(!(data->getFuncReference()->getShowable()));

        // Notification
        data->view->notificationGraphe();
    }
}

void ManageFunc::setMinMax(QCPRange range)
{
    bool VmaxZoom = false;
    bool VminZoom = false;
    bool VmaxZoom_out = false;
    bool VminZoom_out = false;

    if(data->getVmax() >= 0)
    {
        VmaxZoom = range.upper < data->getVmax()/1.2;
        VmaxZoom_out = range.upper > data->getVmax()*1.2;
    }
    else
    {
        VmaxZoom = range.upper < data->getVmax()*1.2;
        VmaxZoom_out = range.upper > data->getVmax()/1.2;
    }

    if(data->getVmin() >= 0)
    {
        VminZoom = range.lower > data->getVmin()*1.2;
        VminZoom_out = range.lower < data->getVmin()/1.2;
    }
    else
    {
        VminZoom = range.lower < data->getVmin()*1.2;
        VminZoom_out = range.lower > data->getVmin()/1.2;
    }

    // Change step by step for not always recalcul the tables
    if((VminZoom || VmaxZoom || VminZoom_out || VmaxZoom_out)
        && data->getFuncIndex(0)->getFunction().compare("y=") > 0)       //if the first function isn't complete
    {
        data->setVmax(range.upper);
        data->setVmin(range.lower);

        // Recalcul all table
        for (std::list<Function*>::iterator it = data->funcList.begin(); it != data->funcList.end(); it++)
            (*it)->createTable();

        // Redraw all graph
        for(int i = 0; i < data->nbrFunction; i++)
            data->view->notificationRedraw(i);
    }
}

 void ManageFunc::selectCmd(QString cmd)
 {

    cmd = cmd.toLower();

    // Check Good cmd wiht ()
    if(cmd.count(QRegExp("(\\()")) == 1 && cmd.count(QRegExp("(\\))")) == 1)
    {
        cmd = cmd.toLower();
        if(cmd.section(QRegExp("(\\())"), 0, 0).contains("setcolor"))
            changeColor(cmd.section(QRegExp("(\\()"), 1, 1).remove(QRegExp("(\\))")));

        else if(cmd.section(QRegExp("(\\())"), 0, 0).contains("setminmax") && cmd.count(QRegExp("(\\,)")) == 1)
            rescaleAxes(cmd.section(QRegExp("(\\()"), 1, 1).remove(QRegExp("(\\))")).section(QRegExp("(,)"),0,0),
                        cmd.section(QRegExp("(\\()"), 1, 1).remove(QRegExp("(\\))")).section(QRegExp("(,)"),1,1));

        else if(cmd.section(QRegExp("(\\())"), 0, 0).contains("setnbrpoint"))
            changeNbrPoint(cmd.section(QRegExp("(\\()"), 1, 1).remove(QRegExp("(\\))")));
    }

    data->view->notificatiponClearCmd();
 }
