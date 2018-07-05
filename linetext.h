#ifndef LINETEXT_H
#define LINETEXT_H

#include <QLineEdit>
#include <QString>

#include "style.h"


class LineText : public QLineEdit
{
    Q_OBJECT

public:
    LineText(QString text, QWidget *parent, int posx, int posy);

public slots:
    void sendText();

signals:
    void sendText(QString text);

};

#endif // LINETEXT_H
