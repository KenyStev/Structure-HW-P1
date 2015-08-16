#ifndef TOMOVE_H
#define TOMOVE_H

#include <QLabel>
#include <vector>
#include <iostream>

using namespace std;

class ToMove
{
public:
    ToMove(QLabel*);
    ToMove();

    void setColor(int);
    void setColor(string);
    void addAdyacente(QLabel *l);
    void addAdyacente(ToMove *tm);

    string getColor();
    vector<ToMove*> getAdyacentes();
    string getVuelta();

private:
    vector<ToMove*> adyacentes;
    QLabel *vuelta;
    string color;
};

#endif // TOMOVE_H
