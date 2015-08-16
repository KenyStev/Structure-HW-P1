#ifndef NODO
#define NODO

class Nodo
{
public:
    Nodo(QString n)
    {
        valor = n;
        next = NULL;
        before = NULL;
    }

    QString valor;
    Nodo *next;
    Nodo *before;
};

#endif // NODO

