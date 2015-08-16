#ifndef NODOC
#define NODOC

#include <QString>

class NodoC
{
public:
    NodoC(QString v,int n)
    {
        next =n;
        valor = v;
    }

    int next;
    QString valor;
};

#endif // NODOC

