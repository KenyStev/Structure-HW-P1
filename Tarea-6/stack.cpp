#include "stack.h"
#include "ui_stack.h"

Stack::Stack(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stack)
{
    ui->setupUi(this);
    Top = NULL;
}

Stack::~Stack()
{
    delete ui;
}

void Stack::fillList()
{
    ui->listStack->clear();
    Nodo* tmp = Top;
    while(tmp)
    {
        QListWidgetItem *item = new QListWidgetItem();
        item->setText(tmp->valor);
        ui->listStack->addItem(item);
        tmp = tmp->next;
    }
}

void Stack::push(QString v)
{
    if(!Top)
    {
        Top = new Nodo(v);
    }else{
        Nodo* tmp = new Nodo(v);
        tmp->next = Top;
        Top = tmp;
    }
}

Nodo* Stack::pop()
{
    if(!Top)
        return NULL;
    Nodo* tmp = Top;
    Top = Top->next;
    return tmp;
}

Nodo* Stack::top()
{
    return Top;
}

void Stack::clear()
{
    if(Top)
    {
        delete pop();
        clear();
    }
}

void Stack::clean()
{
    if(Top)
    {
        pop();
        clean();
    }

}

void Stack::on_btnPush_clicked()
{
    QString V = ui->txtValor->text();
    if(V!="")
    {
        push(V);
        ui->txtTop->setText(Top->valor);
        ui->txtValor->setText("");
        fillList();
    }
    else
        QMessageBox::warning(this,"Error!","No hay valor para agregar");
}

void Stack::on_btnPop_clicked()
{
    Nodo* t = pop();
    if(t)
    {
        QMessageBox::information(this,"Top!","El Top era: " + t->valor);
        ui->txtValor->setText(t->valor);
        if(Top)
            ui->txtTop->setText(Top->valor);
        else
            ui->txtTop->setText("");
        fillList();
    }
}

void Stack::on_btnTop_clicked()
{
    Nodo* t = top();
    if(t)
    {
        QMessageBox::information(this,"Top!","El Top es: " + t->valor);
        ui->txtValor->setText(t->valor);
        fillList();
    }
}

void Stack::on_btnClean_clicked()
{
    clean();
    ui->listStack->clear();
    ui->txtTop->setText("");
    ui->txtValor->setText("");
}

void Stack::on_btnClear_clicked()
{
    clear();
    ui->listStack->clear();
    ui->txtTop->setText("");
    ui->txtValor->setText("");
}
