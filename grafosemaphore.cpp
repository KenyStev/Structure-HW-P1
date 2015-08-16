#include "grafosemaphore.h"
#include "ui_grafosemaphore.h"

GrafoSemaphore::GrafoSemaphore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GrafoSemaphore)
{
    ui->setupUi(this);
}

GrafoSemaphore::~GrafoSemaphore()
{
    delete ui;
}
