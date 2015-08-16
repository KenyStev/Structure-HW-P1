#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Tarea-1/grafosemaphore.h"
#include "Tarea-2/duplicados.h"
#include "Tarea-3/arrayas.h"
#include "Tarea-4/list.h"
#include "Tarea-5/cursor.h"
#include "Tarea-6/stack.h"
#include "Tarea-7/queue.h"
#include "Tarea-8/tree.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    GrafoSemaphore *ventana = new GrafoSemaphore();
    ventana->show();
}

void MainWindow::on_duplicadosButton_clicked()
{
    Duplicados *ventana = new Duplicados();
    ventana->show();
}

void MainWindow::on_duplicadosButton_2_clicked()
{
    Arrayas *ventana = new Arrayas();
    ventana->show();
}

void MainWindow::on_duplicadosButton_3_clicked()
{
    List *ventana = new List();
    ventana->show();
}

void MainWindow::on_duplicadosButton_4_clicked()
{
    Cursor *ventana = new Cursor();
    ventana->show();
}

void MainWindow::on_duplicadosButton_5_clicked()
{
    Stack *ventana = new Stack();
    ventana->show();
}

void MainWindow::on_duplicadosButton_6_clicked()
{
    Queue *ventana = new Queue();
    ventana->show();
}

void MainWindow::on_duplicadosButton_7_clicked()
{
    Tree *ventana = new Tree();
    ventana->show();
}
