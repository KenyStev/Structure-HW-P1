#include "queue.h"
#include "ui_queue.h"

Queue::Queue(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Queue)
{
    ui->setupUi(this);
    root = NULL;
    end = NULL;
}

Queue::~Queue()
{
    delete ui;
}

void Queue::fillList()
{
    ui->listQueue->clear();
    Nodo* tmp = root;
    while(tmp)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(tmp->valor);
        ui->listQueue->addItem(item);
        tmp = tmp->next;
    }
}

void Queue::push(QString v)
{
    if(!root)
    {
        root = new Nodo(v);
        end = root;
    }else{
        end->next = new Nodo(v);
        end->next->before = end;
        end = end->next;
    }
}

Nodo *Queue::pop()
{
    if(!root)
        return NULL;
    Nodo *tmp = root;
    root = tmp->next;
    return tmp;
}

Nodo *Queue::first()
{
    return root;
}

void Queue::clear()
{
    if(root)
    {
        delete pop();
        clear();
    }
}

void Queue::clean()
{
    if(root)
    {
        delete pop();
        clean();
    }
}

void Queue::on_btnPush_clicked()
{
    QString v = ui->txtValor->text();
    if(v!="")
    {
        push(v);
        ui->txtRoot->setText(root->valor);
        ui->txtEnd->setText(end->valor);
        ui->txtValor->setText("");
        fillList();
    }
}

void Queue::on_btnPop_clicked()
{
    Nodo* t = pop();
    if(t)
    {
        QMessageBox::information(this,"Root!","El Root era: " + t->valor);
        ui->txtValor->setText(t->valor);
        if(root)
            ui->txtRoot->setText(root->valor);
        else
            ui->txtRoot->setText("");
        fillList();
    }
}

void Queue::on_btnFirst_clicked()
{
    Nodo* t = first();
    if(t)
    {
        QMessageBox::information(this,"First!","El first es: " + t->valor);
        ui->txtValor->setText(t->valor);
        fillList();
    }
}

void Queue::on_btnClean_clicked()
{
    clean();
    ui->listQueue->clear();
    ui->txtRoot->setText("");
    ui->txtEnd->setText("");
    ui->txtValor->setText("");
}

void Queue::on_btnClear_clicked()
{
    clear();
    ui->listQueue->clear();
    ui->txtRoot->setText("");
    ui->txtEnd->setText("");
    ui->txtValor->setText("");
}
