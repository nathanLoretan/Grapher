#include "table.h"

Table::Table(QWidget *parent, int posx, int posy):
    QTableWidget(DFLT_NBR_ROW, DFLT_NBR_COLUMN, parent)
{
    this->setColumnsSize(TABLE_CELLX);
    this->setRowsSize(TABLE_CELLY);
    this->setGeometry(posx, posy, TABLE_WIDTH, TABLE_HEIGHT);
    this->verticalHeader()->setFixedWidth(TABLE_ID);
    this->verticalHeader()->setDefaultAlignment(Qt::AlignCenter |
                                                Qt::AlignVCenter);

    itemX = new QTableWidgetItem;
    itemX->setText("X");
    this->setHorizontalHeaderItem(0, itemX);

    itemY = new QTableWidgetItem;
    itemY->setText("Y");
    this->setHorizontalHeaderItem(1, itemY);

    this->horizontalHeader()->setStretchLastSection(true);
    this->lock();

    // Design
    this->setStyleSheet
    (
        "QTableWidget{"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0   rgb(70, 70, 70),"
        "stop: 1.0 rgb(70, 70, 70));"
        "color: white;"
        "border-radius: 5px;}"
        ""
        "QHeaderView::section {"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0   rgb(100, 100, 100),"
        "stop: 0.2 rgb(100, 100, 100),"
        "stop: 0.4 rgb(70, 70, 70),"
        "stop: 1.0 rgb(70, 70, 70));"
        "color: white;"
        "border: black}"
        ""
        "QTableWidget QTableCornerButton::section{"
        "background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,"
        "stop: 0   rgb(100, 100, 100),"
        "stop: 0.2 rgb(100, 100, 100),"
        "stop: 0.4 rgb(70, 70, 70),"
        "stop: 1.0 rgb(70, 70, 70));"
        "border:black;}"
        ""
        "QScrollBar:horizontal {"
        "background-color: rgb(70, 70, 70);"
        "border: 2px rgb(70, 70, 70);}"
        ""
        "QScrollBar::handle:horizontal {}"
        ""
        "QScrollBar:vertical {"
        "width: 10px;"
        "background-color: rgb(70, 70, 70);"
        "border: 2px rgb(70, 70, 70);}"
    );
}

Table::~Table()
{
    delete itemX;
    delete itemY;
}

void Table::setRowsSize(int height)
{
    for(int i = 0; i < this->rowCount(); i++)
        this->setRowHeight(i, height);
}

void Table::setColumnsSize(int width)
{
    for(int i = 0; i < this->columnCount(); i++)
        this->setColumnWidth(i, width);
}

void Table::lock()
{
    for(int row = 0; row < this->rowCount(); row++)
    {
        for(int column = 0; column < this->columnCount(); column++)
        {
            QTableWidgetItem *item = new QTableWidgetItem();

            // Can't write on the cell and can't select the cell
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            item->setFlags( item->flags() ^ Qt::ItemIsSelectable);

            this->setItem(row, column, item);
            this->repaint();
        }
    }
}

void Table::setNbrCount(int count)
{
    this->setRowCount(count);
    this->setRowsSize(TABLE_CELLY);
    this->lock();
}
