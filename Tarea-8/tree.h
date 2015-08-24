#ifndef TREE_H
#define TREE_H

#include <QMainWindow>
#include "Tarea-8/nodo.h"
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QString>

namespace Ui {
class Tree;
}

class Tree : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tree(QWidget *parent = 0);
    ~Tree();

    void add(int,Nodo*&);
    Nodo* search(int);
    Nodo* search(int,Nodo*);
    void dispose(int,Nodo*&);
    QString preOrder(Nodo*);
    QString inOrder(Nodo*);
    QString postOrder(Nodo*);


private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnSeach_clicked();

    void on_btnPreOrden_clicked();

    void on_btnInOrden_clicked();

    void on_btnPostOrden_clicked();

private:
    Ui::Tree *ui;
    Nodo *root;

    void fillTree();
    QTreeWidgetItem* fillTree(Nodo*,QString);
};

#endif // TREE_H
