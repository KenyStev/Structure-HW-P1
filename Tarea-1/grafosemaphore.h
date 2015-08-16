#ifndef GRAFOSEMAPHORE_H
#define GRAFOSEMAPHORE_H

#include <QMainWindow>
#include "tomove.h"
#include <iostream>
#include <vector>
#include <QMessageBox>

using namespace std;

namespace Ui {
class GrafoSemaphore;
}

class GrafoSemaphore : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrafoSemaphore(QWidget *parent = 0);
    ~GrafoSemaphore();

    ToMove* getNodoLibre();
    void llenarGrafo();
    void asignarColores();

private slots:
    void on_Create_clicked();

private:
    Ui::GrafoSemaphore *ui;
    vector<ToMove*> grafo;

    QMessageBox msj;
    string getNewColor();
    string getColor();
    string colores[4] = {"QLabel {color : red; }","QLabel {color : yellow; }","QLabel {color : blue; }","QLabel {color : green; }"};
    string colors[4] = {"red","yellow","blue","green"};
    //colores[0]="QLabel {color : red};";
    int c=-1;
};

#endif // GRAFOSEMAPHORE_H
