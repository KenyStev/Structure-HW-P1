#ifndef CURSOR_H
#define CURSOR_H

#include <QMainWindow>
#include "Tarea-5/nodoc.h"
#include <QStringList>
#include <QListWidgetItem>
#include <QMessageBox>

namespace Ui {
class Cursor;
}

class Cursor : public QMainWindow
{
    Q_OBJECT

public:
    QString v;
    explicit Cursor(QWidget *parent = 0);
    ~Cursor();

    void add(int,QString);
    void insert(int,QString,QString);
    void dispose(int,QString);
    int search(int,QString);
    int searchBefore(int,QString);

private slots:\

    void on_btnAdd_clicked();

    void on_btnDelete_clicked();

    void on_btnInsert_clicked();

    void on_btnSearch_clicked();

    void on_btnCreate_clicked();

    void on_cmbLists_activated(const QString &arg1);

private:
    Ui::Cursor *ui;
    const static int size = 20;
    NodoC array[size];
    int lists[size];
    int disponible,lists_cant;

    void initCursor();
    void fillList(int);
    void reloadLists();
    int getLast(int);
    void desplazar(int index,bool right);
};

#endif // CURSOR_H
