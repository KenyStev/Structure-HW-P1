#include "arrayas.h"
#include "ui_arrayas.h"

Arrayas::Arrayas(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Arrayas)
{
    ui->setupUi(this);
    size=20;
    cont=0;
}

Arrayas::~Arrayas()
{
    delete ui;
}

void Arrayas::desplazar(int index,bool right)
{
    if(right)
    {
        for(int i = cont+1;i>0;i--)
        {
            array[i] = array[i-1];
        }
    }else{
        for(int i = index+1;i<=cont;i++)
        {
            array[i-1] = array[i];
        }
    }
}

void Arrayas::add(QString valor)
{
    if(cont<size)
        array[cont++] = valor;
    print();
}

void Arrayas::suprime(int index)
{
    if(index<cont)
        desplazar(index,false);
    cont--;
    print();
}

void Arrayas::insert(int index,QString val)
{
    if(index>cont)
    {
        add(val);
    }else{
        desplazar(index,true);
        array[index] = val;
        cont++;
    }
    print();
}

void Arrayas::print()
{
    QString lbl="";
    for(int i=0; i<cont; i++)
    {
        lbl.append("| "+array[i]+" |");
    }
    ui->lblArray->setText(lbl);
}

void Arrayas::clear()
{
    ui->valor->setText("");
    ui->index->setText("");
}

void Arrayas::on_btnAdd_clicked()
{
    add(ui->valor->text());
    clear();
}

void Arrayas::on_btnDelete_clicked()
{
    suprime(ui->index->text().toInt());
    clear();
}

void Arrayas::on_btnInsert_clicked()
{
    insert(ui->index->text().toInt(),ui->valor->text());
    clear();
}

void Arrayas::on_btnClear_clicked()
{
    cont=0;
    print();
    clear();
}
