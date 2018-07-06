#include "help.h"

Help::Help(QWidget *parent, QPalette pal) : QDialog(parent)
{
    this->setGeometry(WIN_POSX, WIN_POSY, HELP_WIN_X, HELP_WIN_Y);
    this->setPalette(pal);
    this->setWindowTitle("Help");
    // this->setVisible(true);

    helpText = new QLabel("", this);
    helpText->setGeometry(MARGIN_X, MARGIN_Y, HELP_WIN_X, HELP_WIN_Y);
    helpText->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    helpText->setFont(QFont("Arial", 10, QFont::Normal));
    helpText->setWordWrap(true);
    helpText->setVisible(true);

    helpText->setStyleSheet(
        "QLabel {color:"HELP_FONT_COLOR"}");

    helpText->setText(QString(
        "<div>"
        "    <h3><u><b>Operation</b>:</u></h3>"
        "    <ul>"
        "        <li>+, -, *, /, abs()</li>"
        "        <li>^, e, exp(), ln(), sqrt()</li>"
        "        <li>sin(), cos(), tan(), arcsin(), arccos(), arcctan()</li>"
        "        <li>{}, [], ()</li>"
        "    </ul>"
        "</div>"
        ""
        "<div>"
        "    <h3><u><b>Command:</b></u></h3>"
        "    <ul>"
        "        <li><i>setcolor(color)</i>: Set the color of the selected line</li>"
        "        <li><i>setminmax(min, max)</i>: Rescale axe-x</li>"
        "        <li><i>setnbrpoint(nbrPoint)</i>: Set the resolution</li>"
        "    </ul>"
        "</div>"
    ));
}

Help::~Help()
{
    delete helpText;
}

void Help::helpPopUp()
{
    this->setVisible(true);
}
