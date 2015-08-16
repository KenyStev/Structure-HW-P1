#ifndef QUEUE_H
#define QUEUE_H

#include <QMainWindow>
#include "Tarea-7/nodo.h"
#include <QMessageBox>
#include <QListWidgetItem>

namespace Ui {
class Queue;
}

class Queue : public QMainWindow
{
    Q_OBJECT

public:
    explicit Queue(QWidget *parent = 0);
    ~Queue();

    void push(QString);
    Nodo* pop();
    Nodo* first();
    void clear();
    void clean();

private slots:
    void on_btnPush_clicked();

    void on_btnPop_clicked();

    void on_btnFirst_clicked();

    void on_btnClean_clicked();

    void on_btnClear_clicked();

private:
    Ui::Queue *ui;
    Nodo* root;
    Nodo* end;

    void fillList();

};

#endif // QUEUE_H
