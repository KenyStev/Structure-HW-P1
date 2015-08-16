#include "cursor.h"
#include "ui_cursor.h"

Cursor::Cursor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cursor)
{
    ui->setupUi(this);
    disponible = 0;
    lists_cant = 0;
    initCursor();
}

Cursor::~Cursor()
{
    delete ui;
}

void Cursor::desplazar(int index,bool right)
{
    if(right)
    {
        for(int i = lists_cant+1;i>0;i--)
        {
            lists[i] = lists[i-1];
        }
    }else{
        for(int i = index+1;i<=lists_cant;i++)
        {
            lists[i-1] = lists[i];
        }
    }
}

void Cursor::initCursor()
{
    for(int i=0; i<size-1;i++)
    {
        array[i].next = i+1;
    }
}

void Cursor::reloadLists()
{
    ui->cmbLists->clear();

    for(int i=0;i<lists_cant;i++)
    {
        QString item = QString("%1").arg(i);
        ui->cmbLists->addItem(item);
    }

}

void Cursor::fillList(int l)
{
    ui->listSelectedData->clear();
    int inicio = l;

    while(inicio!=-1)
    {
        QString inicioS = QString("%1").arg(inicio);
        QListWidgetItem *item = new QListWidgetItem();
        item->setText("index: "+inicioS+" - Valor: "+array[inicio].valor);
        ui->listSelectedData->addItem(item);
        inicio = array[inicio].next;
    }

}

void Cursor::add(int l,QString v)
{
    if(disponible!=-1)
    {
        int nextFree = disponible, last = getLast(l);
        disponible = array[disponible].next;
        array[last].next = nextFree;
        array[nextFree].valor = v;
        array[nextFree].next = -1;
    }
}

// l = index of lists array in this function
void Cursor::insert(int l,QString IV,QString v)
{
    if(disponible!=-1)
    {
        int pos = search(lists[l],IV);

        if(pos==lists[l])
        {
            int nextFree = disponible;
            disponible = array[disponible].next;
            array[nextFree].valor = v;
            array[nextFree].next = pos;
            lists[l] = nextFree;
        }else if(pos==-1){
            add(lists[l],v);
        }else{
            int anterior = searchBefore(lists[l],IV);
            int nextFree = disponible;
            disponible = array[disponible].next;
            //int oldNext = pos;
            array[nextFree].valor = v;
            array[nextFree].next = pos;
            array[anterior].next = nextFree;
        }
        //fillList(lists[l]);
    }
}

void Cursor::dispose(int l,QString v)
{
    int pos = search(lists[l],v);
    if(pos == lists[l])
    {
        int newRoot = array[pos].next;
        if(newRoot==-1)
        {
            return;
        }
        array[pos].valor="";
        array[pos].next=disponible;
        disponible = pos;
        lists[l] = newRoot;
        /*if(newRoot==-1)
        {
            //desplazar(l,false);
            lists_cant--;
            reloadLists();
        }*/
    }else if(pos!=-1){
        int anterior = searchBefore(lists[l],v);
        int newNext = array[pos].next;
        array[pos].valor="";
        array[pos].next=disponible;
        array[anterior].next = newNext;
        disponible = pos;
    }
}

int Cursor::search(int l,QString v)
{
    if(l!=-1){
        if(array[l].valor==v)
            return l;
        return search(array[l].next,v);
    }
    return -1;
}

int Cursor::searchBefore(int l,QString v)
{
    if(l!=-1)
    {
        int n = array[l].next;
        if(n!=-1)
        {
            if(array[n].valor==v)
                return l;
            return searchBefore(n,v);
        }
    }
    return -1;
}

int Cursor::getLast(int l)
{
    if(array[l].next==-1)
        return l;
    return getLast(array[l].next);
}

void Cursor::on_btnAdd_clicked()
{
    int l = ui->cmbLists->currentText().toInt();
    if(ui->cmbLists->count()==0){
        QMessageBox::warning(this,"Error","No hay ninguna lista creada");
        return;
    }
    QString V = ui->txtValor->text();
    if(V!="")
    {
        add(lists[l],V);
        //reloadLists();
        fillList(lists[l]);
    }else
        QMessageBox::warning(this,"Error","No hay ningun valor a agregar");
}

void Cursor::on_btnDelete_clicked()
{
    int l = ui->cmbLists->currentText().toInt();
    if(ui->cmbLists->count()==0){
        QMessageBox::warning(this,"Error","No hay ninguna lista creada");
        return;
    }
    QString V = ui->txtValor->text();
    if(V!="")
    {
        dispose(l,V);
        fillList(lists[l]);
    }
    else
        QMessageBox::warning(this,"Error","No hay ningun valor a eliminar");
}

void Cursor::on_btnInsert_clicked()
{
    int l = ui->cmbLists->currentText().toInt();
    if(ui->cmbLists->count()==0){
        QMessageBox::warning(this,"Error","No hay ninguna lista creada");
        return;
    }
    QString IV = ui->txtBefore->text(), V = ui->txtValor->text();
    if(IV!="" && V!="")
    {
        insert(l,IV,V);
        //reloadLists();
        fillList(lists[l]);
    }
    else
        QMessageBox::warning(this,"Error","No hay ningun valor a agregar o indice");
}

void Cursor::on_btnSearch_clicked()
{

}

void Cursor::on_btnCreate_clicked()
{
    int l = disponible;
    if(l==-1)
    {
        QMessageBox::warning(this,"Error","No hay mas disponibles!");
        return;
    }
    QString v = ui->txtNewList->text();
    if(v!="")
    {
        lists[lists_cant] = l;
        disponible = array[lists_cant].next;
        array[l].next = -1;
        array[l].valor = v;
        lists_cant++;
        reloadLists();
        fillList(lists[l]);
    }
}

void Cursor::on_cmbLists_activated(const QString &arg1)
{

    fillList(lists[arg1.toInt()]);
}
