#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList> //Para uso de STL listas
#include "paredsolida.h"
#include "paredladrillo.h"
#include <cstdlib> //Para generacion de numeros aleatorios

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    paredLadrillo *ladrillo;
    QList <paredSolida*>paredesSolidas;
    QList <paredSolida*>::Iterator itSol;
    QList <paredLadrillo*>paredesLadrillos;
    QList <paredLadrillo*>::Iterator itLad;


};
#endif // MAINWINDOW_H
