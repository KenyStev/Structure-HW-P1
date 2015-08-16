#include "list.h"
#include "ui_list.h"

List::List(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::List)
{
    ui->setupUi(this);
    root = NULL;
    end = NULL;
}

List::~List()
{
    delete ui;
    delete root;
    delete end;
}

void List::print()
{
    ui->listW->clear();
    Nodo *tmp = root;
    while(tmp)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(tmp->valor);
        ui->listW->addItem(item);
        tmp = tmp->next;
    }
    clear();
}

void List::clear()
{
    ui->valor->setText("");
    ui->before->setText("");
}

void List::add(QString v)
{
    if(!root)
    {
        root = new Nodo(v);
        end = root;
    }else{
        end->next = new Nodo(v);
        end = end->next;
    }
}
//luis.isaula94@gmail.com
bool List::insert(QString vIndex,QString v)
{
    if(!root)
    {
        add(v);
        return false;
    }else{
        Nodo *tmp = search(vIndex);
        if(tmp)
        {
            Nodo *newNodo = new Nodo(v);
            if(root->valor==tmp->valor)
            {
                newNodo->next = root;
                root = newNodo;
                return true;
            }
            Nodo *before = searchBefore(vIndex);
            newNodo->next = tmp;
            before->next = newNodo;
            return true;
        }
    }
}

Nodo* List::search(QString v)
{
    return search(v,root);
}

Nodo* List::search(QString v, Nodo* r)
{
    if(r)
    {
        if(r->valor==v)
            return r;
        return search(v,r->next);
    }
    return NULL;
}

Nodo* List::searchBefore(QString v)
{
    Nodo *tmp = root;
    while (tmp->next) {
        if(tmp->next->valor==v)
            return tmp;
    }
    return NULL;
}

void List::dispose(QString v)
{
    if(root)
    {
        if(root->valor==v)
        {
            Nodo *tmp = root;
            root = root->next;
            //delete tmp;
        }else{
            Nodo *tmp = searchBefore(v);
            if(tmp)
            {
                Nodo *t = tmp->next;
                tmp->next = t->next;
                //delete t;
            }
        }
    }
}

void List::on_add_clicked()
{
    QString v = ui->valor->text();
    if(v=="")
        QMessageBox::warning(this,"Error","Escriba un valor a agregar!");
    else{
        add(v);
        print();
    }
}

void List::on_delete_2_clicked()
{
    QString v = ui->valor->text();
    if(v=="")
        QMessageBox::warning(this,"Error","Escriba un valor a eliminar!");
    else{
        dispose(v);
        print();
    }
}

void List::on_search_clicked()
{
    QString v = ui->valor->text();
    if(v=="")
        QMessageBox::warning(this,"Error","Escriba un valor a buscar!");
    else
    {
        Nodo *n = search(v);
        if(n)
            QMessageBox::information(this,"Encontrado",n->valor);
        else
            QMessageBox::information(this,"No Encontrado",v);
    }
}

void List::on_insert_clicked()
{
    QString b = ui->before->text(),
            v = ui->valor->text();
    if(v=="" || b=="")
        QMessageBox::warning(this,"Error","Escriba un valor a insertar!");
    else{
        insert(b,v);
        print();
    }
}
