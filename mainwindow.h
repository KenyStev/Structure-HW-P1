#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Tarea-1/grafosemaphore.h"
#include "Tarea-2/duplicados.h"
#include "Tarea-3/arrayas.h"
#include "Tarea-4/list.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_duplicadosButton_clicked();

    void on_duplicadosButton_2_clicked();

    void on_duplicadosButton_3_clicked();

    void on_duplicadosButton_4_clicked();

    void on_duplicadosButton_5_clicked();

    void on_duplicadosButton_6_clicked();

    void on_duplicadosButton_7_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
