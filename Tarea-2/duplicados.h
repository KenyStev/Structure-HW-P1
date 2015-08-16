#ifndef DUPLICADOS_H
#define DUPLICADOS_H

#include <QMainWindow>
#include <iostream>
#include <QString>
#include <QListWidgetItem>
#include <vector>

using namespace std;

namespace Ui {
class Duplicados;
}

class Duplicados : public QMainWindow
{
    Q_OBJECT

public:
    explicit Duplicados(QWidget *parent = 0);
    ~Duplicados();

private slots:
    void on_deleteDuplicates_clicked();
    void fillArray();
    void on_addButton_clicked();

private:
    Ui::Duplicados *ui;
    //vector<QString> cartas;
    vector<QString> getArray();
    vector<QString> deleteDuplicates(vector<QString>);

};

#endif // DUPLICADOS_H
