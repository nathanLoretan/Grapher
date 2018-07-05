#include "mainWindows.h"

MainWindows::MainWindows(QWidget *parent):
    QMainWindow(parent)
{
    //Window and Background
    this->setGeometry(WIN_POSX, WIN_POSY, WIN_X, WIN_Y);
    this->setWindowTitle("Grapher");
    this->setFixedSize(this->size());

    // // Background of the window
    // QLinearGradient backGradient;
    // backGradient.setStart(0, 0);
    // backGradient.setFinalStop(0, 350);
    // backGradient.setColorAt(0, BACKGROUND_0);
    // backGradient.setColorAt(1, BACKGROUND_1);

    QPalette pal = this->palette();
    pal.setBrush(QPalette::Window, BACKGROUND);
    // pal.setBrush(QPalette::Highlight, BACKGROUND);
    // pal.setBrush(QPalette::Text, FONT_COLOR);

    this->setAutoFillBackground(true);
    this->setPalette(pal);

    // Pop up window
    helpWindow = new Help(this, pal);

    // Buttons
    buttonDraw      = new Button("Draw",    this, BTN_DRAW_POSX, BTN_DRAW_POSY);
    buttonNew       = new Button("New",     this, BTN_NEW_POSX,  BTN_NEW_POSY);
    buttonRemove    = new Button("Remove",  this, BTN_REM_POSX,  BTN_REM_POSY);
    buttonHelp      = new Button("help",    this, BTN_HELP_POSX, BTN_HELP_POSY);

    // LineText
    editFunc  = new LineText("y=", this, EDIT_FUNC_POSX, EDIT_FUNC_POSY);
    editCmd   = new LineText("command", this, EDIT_CMD_POSX, EDIT_CMD_POSY);

    // QLabel
    nbrPoint = new QLabel("Number of Points: ", this);
    nbrPoint->setGeometry(LBL_NBRP_POSX, LBL_NBRP_POSY, LBL_WIDTH, LBL_HEIGHT);
    nbrPoint->setFont(QFont(FONT_TYPE, FONT_SIZE, QFont::Normal));
    nbrPoint->setStyleSheet("QLabel { color : white;}");

    // cmd = new QLabel("Command: ", this);
    // cmd->setGeometry(LBL_CMD_POSX, LBL_CMD_POSY, LBL_WIDTH, LBL_HEIGHT);
    // cmd->setFont(QFont(FONT_TYPE, FONT_SIZE, QFont::Normal));
    // cmd->setStyleSheet("QLabel { color : white;}");
    //
    // func = new QLabel("Function f(x): (ex y=x+1) ", this);
    // func->setGeometry(LBL_FUNC_POSX, LBL_FUNC_POSY, LBL_WIDTH, LBL_HEIGHT);
    // func->setFont(QFont(FONT_TYPE, FONT_SIZE, QFont::Normal));
    // func->setStyleSheet("QLabel { color : white;}");

    //List
    listFunc = new List(this, LIST_FUNC_POSX, LIST_FUNC_POSY);

    //Table
    table = new Table(this, TABLE_POSX, TABLE_POSY);

    //Graphic
    graph = new Graphic(this, GRAPH_POSX, GRAPH_POSY);
}

MainWindows::~MainWindows()
{
    // Delete View Object
    delete buttonDraw;
    delete buttonNew;
    delete buttonRemove;
    delete buttonHelp;
    delete editCmd;
    delete editFunc;
    delete listFunc;
    delete table;
    delete graph;
    delete helpWindow;
}

void MainWindows::initRelations(ManageFunc *m, Model *mo)
{
    // Model
    data = mo;

    //Manager
    manager = m;

    nbrPoint->setText("Number of Points: " +
                                        QString::number(data->getNbrPoint()));

    //Button Slot
    QObject::connect(buttonDraw, SIGNAL(clicked()), manager,
                                                    SLOT(drawable()));
    QObject::connect(buttonNew, SIGNAL(clicked()), manager,
                                                    SLOT(newFunction()));
    QObject::connect(buttonRemove, SIGNAL(clicked()), manager,
                                                    SLOT(deleteFunction()));
    QObject::connect(buttonHelp, SIGNAL(clicked()), helpWindow,
                                                    SLOT(helpPopUp()));

    //LineEdit Slot
    QObject::connect(editFunc, SIGNAL(sendText(QString)), manager,
                                                SLOT(changeFuncName(QString)));
    QObject::connect(editFunc, SIGNAL(returnPressed()), editFunc,
                                                SLOT(sendText()));
    QObject::connect(editCmd, SIGNAL(sendText(QString)), manager,
                                                SLOT(selectCmd(QString)));
    QObject::connect(editCmd, SIGNAL(returnPressed()), editCmd,
                                                SLOT(sendText()));

    //List Slot
    QObject::connect(listFunc, SIGNAL(currentIndexChanged(int)), manager,
                                                SLOT(selectFunc(int)));

    // Graph Sot
    QObject::connect(graph->xAxis, SIGNAL(rangeChanged(QCPRange)), manager,
                                                SLOT(setMinMax(QCPRange)));
}

void MainWindows::notificationNew()
{
    listFunc->addItem(data->getFunction(), QVariant(QString()));
    listFunc->setCurrentIndex(data->getFuncSelected());
    editFunc->setText(data->getFunction());
}

void MainWindows::notificationSave()
{
    // Create a new graph
    graph->addGraph();
    graph->graph(data->getFuncSelected())->setPen(
                                    QPen(data->getFuncReference()->getColor()));
    graph->graph(data->getFuncSelected())->setData(
                                    data->getFuncReference()->getTableX(),
                                    data->getFuncReference()->getTableY());
    graph->graph(data->getFuncSelected())->rescaleAxes();
    graph->replot();

    listFunc->setItemText(data->getFuncSelected(), data->getFunction());
    editFunc->setText(data->getFunction());
}

void MainWindows::notificationRemove()
{
    graph->removeGraph(data->getFuncSelected());
    graph->replot();

    listFunc->removeItem(data->getFuncSelected());
    editFunc->setText(data->getFunction());

    // resize graph
    //graph->graph(data->getFuncSelected())->rescaleAxes();
}

void MainWindows::notificationIndex()
{
    editFunc->setText(listFunc->itemText(data->getFuncSelected()));
}

void MainWindows::notificationTable()
{
    table->setNbrCount(data->getNbrPoint());

    for(int row = 0; row < table->rowCount(); row++)
    {
        QTableWidgetItem* item = table->item(row, 0);
        item->setText(QString::number(
                        data->getFuncReference()->getTableValueX(row), 'g', 2));
        item->setTextAlignment(Qt::AlignRight);
        // table->setItem(row, 0, item);

        item = table->item(row, 1);
        item->setText(QString::number(
                        data->getFuncReference()->getTableValueY(row), 'g', 2));
        item->setTextAlignment(Qt::AlignRight);
        // table->setItem(row, 1, item);
    }
}

void MainWindows::notificationGraphe()
{
    if(data->getFuncReference()->getShowable())
    {
        graph->graph(data->getFuncSelected())->setVisible(true);
        graph->graph(data->getFuncSelected())->setPen(QPen(
                                        data->getFuncReference()->getColor()));
        graph->graph(data->getFuncSelected())->rescaleAxes();
        graph->replot();
    }
    else
        graph->graph(data->getFuncSelected())->setVisible(false);
}

void MainWindows::notificatiponClearCmd()
{
    editCmd->setText("");
    nbrPoint->setText("Number of Points: " + QString::number(
                                                        data->getNbrPoint()));
}

void MainWindows::notificationRedraw(int index)
{
    if(data->getFuncIndex(index)->getShowable())
    {
        graph->graph(index)->setData(
                                    data->getFuncIndex(index)->getTableX(),
                                    data->getFuncIndex(index)->getTableY());
        graph->replot();
    }
}
