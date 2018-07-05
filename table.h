#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>
#include <QHeaderView>

#include "style.h"

class Table : public QTableWidget
{
private:
    QTableWidgetItem *itemX;
    QTableWidgetItem *itemY;

public:
    Table(QWidget *parent, int posx, int posy);
    ~Table();

    void lock();
    void setRowsSize(int height);
    void setColumnsSize(int width);
    void setNbrCount(int count);
};

#endif // TABLE_H
