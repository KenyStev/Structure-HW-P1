#ifndef NODO
#define NODO

#include <iostream>
#include <QString>

class Nodo
{
public:
    Nodo(QString v)
    {
        valor = v;
        next = NULL;
    }

    QString valor;
    Nodo *next;
};

#endif // NODO

