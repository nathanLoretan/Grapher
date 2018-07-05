#ifndef WINDOWS_H
#define WINDOWS_H

#include <QMainWindow>
#include <QVariant>

#include "style.h"
#include "button.h"
#include "graphic.h"
#include "table.h"
#include "linetext.h"
#include "list.h"
#include "managefunc.h"
#include "observer.h"
#include "model.h"
#include "help.h"
#include "qcustomplot/qcustomplot.h"

class MainWindows : public QMainWindow, public Observer
{
    Q_OBJECT

private:

    // View Object
    QLabel      *nbrPoint;
    QLabel      *cmd;
    QLabel      *func;

    Button      *buttonNew;
    Button      *buttonRemove;
    Button      *buttonDraw;
    Button      *buttonHelp;

    LineText    *editCmd;
    LineText    *editFunc;

    Graphic     *graph;

    Table       *table;

    List        *listFunc;

    Help        *helpWindow;

    // Controler Object
    ManageFunc  *manager;

    // Model Objects
    Model       *data;

public:
     explicit MainWindows(QWidget *parent = 0);
    ~MainWindows();

    void initRelations(ManageFunc *m, Model *mo);

    void notificationNew();
    void notificationSave();
    void notificationIndex();
    void notificationTable();
    void notificationGraphe();
    void notificationRemove();
    void notificatiponClearCmd();
    void notificationRedraw(int index);
};

#endif // WINDOWS_H
