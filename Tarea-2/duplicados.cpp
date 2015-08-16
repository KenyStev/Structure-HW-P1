#include "duplicados.h"
#include "ui_duplicados.h"

Duplicados::Duplicados(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Duplicados)
{
    ui->setupUi(this);
}

Duplicados::~Duplicados()
{
    delete ui;
}
vector<QString> Duplicados::getArray()
{
    int size = ui->Array1->count();
    cout<<"size: "<<size<<endl;

    vector<QString> c;

    for(int i=0;i<size;i++)
    {
        c.push_back(ui->Array1->item(i)->text());
        cout<<ui->Array1->item(i)->text().toStdString()<<endl;
    }
    cout<<"termino de pasar los datos"<<endl;

    return c;
}

vector<QString> Duplicados::deleteDuplicates(vector<QString> c)
{
    vector<QString> carts;
    bool agregar = true;
    for(int i=0; i<c.size(); i++)
    {
        agregar = true;
        for(int j=0; j<carts.size();j++)
        {
            if(carts[j]==c[i])
            {
                agregar = false;
            }
        }
        if(agregar)
            carts.push_back(c[i]);
    }
    return carts;
}

void Duplicados::on_deleteDuplicates_clicked()
{
    vector<QString> cartas = deleteDuplicates(getArray());

    ui->Array2->clear();

    cout<<"imprimendo data 2"<<endl;
    for(int i=0; i<cartas.size(); i++)
    {
        cout<<cartas[i].toStdString()<<endl;
    }
    cout<<"termino de imprimir data"<<endl;

    for(int i=0;i<cartas.size();i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(cartas[i]);
        if(item->text()!="")
            ui->Array2->addItem(item);
    }

    /*int size = 12;
    char carts[size] = {'a','b','c','d','a','b','c','e','f','a','b','g'};

    for(int i=0; i<size; i++)
    {
        for(int j=i+1; j<size;j++)
        {
            if(carts[i]==carts[j])
            {
                //cout<<"es igual: "<<carts[i].toStdString()<<endl;
                for(int k=j+1;k<size;k++)
                {
                    carts[k-1]=carts[k];
                }
                carts[--size]=' ';
                //size_nuevas++;
            }
        }
    }

    for(int i=0; i<size; i++)
    {
        cout<<carts[i];
    }*/
}

void Duplicados::on_addButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem();
    item->setText(ui->newItem->text());
    if(item->text()!="")
        ui->Array1->addItem(item);

    ui->newItem->setText("");
}

void Duplicados::fillArray()
{
    /*
    cartas.push_back("a");
    cartas.push_back("e");
    cartas.push_back("r");
    cartas.push_back("t");
    cartas.push_back("d");
    cartas.push_back("d");
    cartas.push_back("s");
    cartas.push_back("a");
    cartas.push_back("e");*/
}
