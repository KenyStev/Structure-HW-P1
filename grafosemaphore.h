#ifndef GRAFOSEMAPHORE_H
#define GRAFOSEMAPHORE_H

#include <QMainWindow>

namespace Ui {
class GrafoSemaphore;
}

class GrafoSemaphore : public QMainWindow
{
    Q_OBJECT

public:
    explicit GrafoSemaphore(QWidget *parent = 0);
    ~GrafoSemaphore();

private:
    Ui::GrafoSemaphore *ui;
};

#endif // GRAFOSEMAPHORE_H
