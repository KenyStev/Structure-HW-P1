#ifndef ARRAYAS_H
#define ARRAYAS_H

#include <QMainWindow>

namespace Ui {
class Arrayas;
}

class Arrayas : public QMainWindow
{
    Q_OBJECT

public:
    explicit Arrayas(QWidget *parent = 0);
    ~Arrayas();

private slots:
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
    void on_btnInsert_clicked();
    void on_btnClear_clicked();

private:
    Ui::Arrayas *ui;
    int size;
    int cont;
    QString array[20];

    void desplazar(int,bool);
    void add(QString);
    void suprime(int);
    void insert(int,QString);
    void print();
    void clear();
};

#endif // ARRAYAS_H
