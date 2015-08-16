#ifndef NODOC
#define NODOC
#include <QString>

class NodoC
{
public:
    NodoC() : NodoC(0,-1)
    {
    }
    NodoC(QString v,int n)
    {
        next =n;
        valor = v;
    }

    int next;
    QString valor;
};
#endif // NODOC

