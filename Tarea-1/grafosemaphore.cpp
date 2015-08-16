#include "grafosemaphore.h"
#include "ui_grafosemaphore.h"

GrafoSemaphore::GrafoSemaphore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GrafoSemaphore)
{
    ui->setupUi(this);
    llenarGrafo();
    msj.setWindowTitle("Color Group");
    c=-1;
}

GrafoSemaphore::~GrafoSemaphore()
{
    delete ui;
}

void GrafoSemaphore::on_Create_clicked()
{
    if(c==-1)
        asignarColores();
    //cout<<"Hola"<<endl;
    //string n = "QLabel {color : red; }";
    //if(grafo[0]->getColor()=="b")
    //    grafo[0]->setColor(getNewColor());
}

string GrafoSemaphore::getNewColor()
{
    return colores[++c];
}

string GrafoSemaphore::getColor()
{
    return colores[c];
}

ToMove* GrafoSemaphore::getNodoLibre()
{
    for(int i=0; i<grafo.size();i++)
    {
        if(grafo[i]->getColor()=="null")
        {
            return grafo[i];
        }
    }
    return NULL;
}

void GrafoSemaphore::asignarColores()
{
    bool asignar;
    while(true)
    {
        ToMove *temp = getNodoLibre();
        if(temp==NULL)
            break;
        temp->setColor(getNewColor());
        for(int i=0; i<grafo.size();i++)
        {
            asignar=true;
            if(grafo[i]->getColor()=="null")
            {
                for(int j=0; j<grafo[i]->getAdyacentes().size();j++)
                {
                    if(grafo[i]->getAdyacentes()[j]->getColor()==getColor())
                    {
                        asignar=false;
                    }
                }
                if(asignar)
                    grafo[i]->setColor(getColor());
            }
        }
    }
}

void GrafoSemaphore::llenarGrafo()
{
    ToMove  *AB = new ToMove(ui->AB),
            *AC = new ToMove(ui->AC),
            *AD = new ToMove(ui->AD),

            *BA = new ToMove(ui->BA),
            *BC = new ToMove(ui->BC),
            *BD = new ToMove(ui->BD),

            *DA = new ToMove(ui->DA),
            *DB = new ToMove(ui->DB),
            *DC = new ToMove(ui->DC),

            *EA = new ToMove(ui->EA),
            *EB = new ToMove(ui->EB),
            *EC = new ToMove(ui->EC),
            *ED = new ToMove(ui->ED);

     AB->addAdyacente(BD);
     AB->addAdyacente(BC);
     AB->addAdyacente(DA);
     AB->addAdyacente(EA);

     AC->addAdyacente(BD);
     AC->addAdyacente(EB);
     AC->addAdyacente(DB);
     AC->addAdyacente(DA);
     AC->addAdyacente(EA);

     AD->addAdyacente(EC);
     AD->addAdyacente(EB);
     AD->addAdyacente(EA);

     BC->addAdyacente(AB);
     BC->addAdyacente(DB);
     BC->addAdyacente(EB);

     BD->addAdyacente(AC);
     BD->addAdyacente(AB);
     BD->addAdyacente(DA);
     BD->addAdyacente(EB);
     BD->addAdyacente(EC);

     DA->addAdyacente(AB);
     DA->addAdyacente(AC);
     DA->addAdyacente(BD);
     DA->addAdyacente(EC);
     DA->addAdyacente(EB);

     DB->addAdyacente(AC);
     DB->addAdyacente(BC);
     DB->addAdyacente(EC);

     EA->addAdyacente(AB);
     EA->addAdyacente(AC);
     EA->addAdyacente(AD);

     EB->addAdyacente(DA);
     EB->addAdyacente(BC);
     EB->addAdyacente(AC);
     EB->addAdyacente(AD);
     EB->addAdyacente(BD);

     EC->addAdyacente(AD);
     EC->addAdyacente(BD);
     EC->addAdyacente(DB);
     EC->addAdyacente(DA);

     grafo.push_back(AB);
     grafo.push_back(AC);
     grafo.push_back(AD);

     grafo.push_back(BA);
     grafo.push_back(BC);
     grafo.push_back(BD);

     grafo.push_back(DA);
     grafo.push_back(DB);
     grafo.push_back(DC);

     grafo.push_back(EA);
     grafo.push_back(EB);
     grafo.push_back(EC);
     grafo.push_back(ED);

     cout<<ED->getVuelta()<<endl;
}
