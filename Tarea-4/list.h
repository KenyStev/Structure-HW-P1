#ifndef LIST_H
#define LIST_H

#include <QMainWindow>
#include "nodo.h"
#include <QString>
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class List;
}

class List : public QMainWindow
{
    Q_OBJECT

public:
    explicit List(QWidget *parent = 0);
    ~List();
    void add(QString);
    bool insert(QString,QString);
    Nodo* search(QString);
    Nodo* search(QString,Nodo*);
    Nodo* searchBefore(QString);
    void dispose(QString);

private slots:
    void on_add_clicked();

    void on_delete_2_clicked();

    void on_search_clicked();

    void on_insert_clicked();

private:
    Ui::List *ui;
    Nodo *root, *end;

    void print();
    void clear();
};

#endif // LIST_H
