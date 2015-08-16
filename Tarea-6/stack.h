#ifndef STACK_H
#define STACK_H

#include <QMainWindow>
#include "Tarea-6/nodo.h"
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class Stack;
}

class Stack : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stack(QWidget *parent = 0);
    ~Stack();

    void push(QString);
    Nodo* pop();
    Nodo* top();
    void clear();
    void clean();

private slots:
    void on_btnPush_clicked();

    void on_btnPop_clicked();

    void on_btnTop_clicked();

    void on_btnClean_clicked();

    void on_btnClear_clicked();

private:
    Ui::Stack *ui;
    Nodo *Top;

    void fillList();
};

#endif // STACK_H
