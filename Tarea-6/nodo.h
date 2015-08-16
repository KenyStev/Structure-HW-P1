#ifndef NODO
#define NODO

#include <QString>

class Nodo
{
public:
    Nodo(QString n)
    {
        valor = n;
        next = NULL;
    }

    QString valor;
    Nodo *next;
};

#endif // NODO

