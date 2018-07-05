#include "help.h"



Help::Help(QWidget *parent, QPalette pal) : QDialog(parent)
{
    this->setGeometry(WIN_POSX, WIN_POSY, WIN_X, WIN_Y);
    this->setPalette(pal);
    this->setWindowTitle("Help");

    helpText = new QLabel("Function f(\nx): (ex y=x+1) ", this);
    helpText->setGeometry( 10, 0, WIN_X, WIN_Y);
    helpText->setFont(QFont( "Arial", 12, QFont::Normal));
    helpText->setStyleSheet("QLabel { color : white;}");
    helpText->setVisible(true);

    helpText->setText(QString(
        "Operation:\n"
        "1. Base:\t\t\t +, -, *, /, abs()\n"
        "2. Power and exponential:\t ^, e, exp(), ln(), sqrt()\n"
        "3. Trigonometric:\t\t sin(), cos(), tan(), arcsin(), arccos(),"
                                                                    "arcctan()\n"
        "4. Separator:\t\t\t {}, [], ()\n\n"
        "Command:\n"
        "1. setcolor(color):\t\t set the color of the selected graph\n"
        "2. setminmax(min, max,):\t rescale axe X and calcul the value with"
                                                                "these values.\n"
        "t\t\t\t The table is update.\n"
        "3. setnbrpoint(nbrPoint):\t set the resolution for drawing the"
                                                                "graphes.\n"));
}

Help::~Help()
{
    delete helpText;
}

void Help::helpPopUp()
{
    this->setVisible(true);
}
