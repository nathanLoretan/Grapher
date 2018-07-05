#ifndef HELP_H
#define HELP_H

#include <QLabel>
#include <QDialog>
#include <QPalette>

#include "style.h"

class Help : public QDialog
{
    Q_OBJECT

private:
    QLabel      *helpText;

public:
    Help(QWidget *parent, QPalette pal);
    ~Help();

public slots:
    void helpPopUp();
};

#endif // HELP_H
