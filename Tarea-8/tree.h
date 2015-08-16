#ifndef TREE_H
#define TREE_H

#include <QMainWindow>
#include "Tarea-8/nodo.h"
#include <QTreeWidgetItem>
#include <QMessageBox>

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

private slots:
    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnSeach_clicked();

private:
    Ui::Tree *ui;
    Nodo *root;

    void fillTree();
    QTreeWidgetItem* fillTree(Nodo*,QString);
};

#endif // TREE_H
