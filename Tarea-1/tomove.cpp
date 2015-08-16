#include "tomove.h"

ToMove::ToMove()
{

}

ToMove::ToMove(QLabel* l)
{
    vuelta = l;
    color = "null";
}

void ToMove::addAdyacente(QLabel *l)
{
    adyacentes.push_back(new ToMove(l));
}

void ToMove::addAdyacente(ToMove *tm)
{
    adyacentes.push_back(tm);
}

string ToMove::getVuelta()
{
    return vuelta->text().toStdString();
}

string ToMove::getColor()
{
    return color;
}

vector<ToMove*> ToMove::getAdyacentes()
{
    return adyacentes;
}

void ToMove::setColor(int c)
{
    switch(c)
    {
        case 0:
            color = "QLabel {color : red;}";
        break;
        case 1:
            color = "QLabel {color : yellow;}";
        break;
        case 2:
            color = "QLabel {color : blue;}";
        break;
        case 3:
            color = "QLabel {color : green;}";
        break;
    }
}

void ToMove::setColor(string c)
{
    color = c;
    vuelta->setStyleSheet(color.c_str());
}
