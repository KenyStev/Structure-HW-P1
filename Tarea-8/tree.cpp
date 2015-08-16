#include "tree.h"
#include "ui_tree.h"

Tree::Tree(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tree)
{
    ui->setupUi(this);
    root=NULL;
}

Tree::~Tree()
{
    delete ui;
}

void Tree::fillTree()
{
    ui->tree->clear();
    QTreeWidgetItem *rootWidget = fillTree(root,"root");
    ui->tree->addTopLevelItem(rootWidget);
}

QTreeWidgetItem* Tree::fillTree(Nodo* root,QString name)
{
    if(!root)
    {
        return NULL;
    }else{
        QTreeWidgetItem *item = new QTreeWidgetItem();
        QString s = QString("%1").arg(root->valor);
        item->setText(0,name + ": " + s);
        item->addChild(fillTree(root->der, "der"));
        item->addChild(fillTree(root->izq, "izq"));
        return item;
    }
}

void Tree::add(int v, Nodo *&root)
{
    if(!root)
    {
        root = new Nodo(v);
    }else{
        if(v > root->valor)
            add(v,root->der);
        else
            add(v,root->izq);
    }
}

Nodo *Tree::search(int v)
{
    return search(v,root);
}

Nodo *Tree::search(int v, Nodo *root)
{
    if(root)
    {
        if(root->valor==v)
            return root;
        else
        {
            if(v > root->valor)
                return search(v,root->der);
            else
                return search(v,root->izq);
        }
    }
    return NULL;
}

void Tree::dispose(int v, Nodo *&root)
{
    if(root)
    {
        if(root->valor==v)
        {
            if(root->der==NULL && root->izq==NULL)
            {
                Nodo*t=root;
                root=NULL;
                delete t;
            }else if(root->der==NULL){
                Nodo*t=root;
                root = root->izq;
                delete t;
            }else{
                Nodo*t=root;
                root = root->der;
                delete t;
            }
        }else{
            dispose(v,root->der);
            dispose(v,root->izq);
        }
    }
}

void Tree::on_btnAdd_clicked()
{
    if(ui->txtValor->text()!="")
    {
        int v = ui->txtValor->text().toInt();
        add(v,root);
        fillTree();
        ui->txtValor->setText("");
    }
}

void Tree::on_btnDelete_clicked()
{
    if(ui->txtValor->text()!="")
    {
        int v = ui->txtValor->text().toInt();
        dispose(v,root);
        fillTree();
    }
}

void Tree::on_btnSeach_clicked()
{
    if(ui->txtValor->text()!="")
    {
        Nodo *n = search(ui->txtValor->text().toInt());
        if(n)
        {
            QTreeWidgetItem *rootWidget = new QTreeWidgetItem();
            rootWidget->setText(0,"Searched: " + QString("%1").arg(n->valor));
            if(n->der)
            {
                QTreeWidgetItem *der = new QTreeWidgetItem();
                der->setText(0,"der: " + QString("%1").arg(n->der->valor));
                rootWidget->addChild(der);
            }
            if(n->izq)
            {
                QTreeWidgetItem *izq = new QTreeWidgetItem();
                izq->setText(0,"izq: " + QString("%1").arg(n->izq->valor));
                rootWidget->addChild(izq);
            }
            ui->treeSearched->addTopLevelItem(rootWidget);
        }else{
            QMessageBox::warning(this,"Error!","No Encontrado");
        }
    }
}
