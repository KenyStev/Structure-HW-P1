#ifndef NODO
#define NODO

#include <QString>

class Nodo
{
public:
    Nodo(int v)
    {
        valor=v;
        izq=NULL;
        der=NULL;
    }

    int valor;
    Nodo *izq, *der;
};

#endif // NODO

