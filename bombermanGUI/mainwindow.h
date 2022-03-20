#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList> //Para uso de STL listas
#include <cstdlib> //Para generacion de numeros aleatorios
#include <QKeyEvent> //Para controlar por teclado
#include "paredsolida.h"
#include "paredladrillo.h"
#include "bomberman.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool evaluarColision(); //Metodo que evalua la colision entre objetos

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList <paredSolida*>paredesSolidas; //Lista de bloques solidos
    QList <paredSolida*>::Iterator itSol;
    QList <paredLadrillo*>paredesLadrillos; //lista de bloques ladrillo
    QList <paredLadrillo*>::Iterator itLad;
    bomberman *bomberman0; //personaje principal
    void keyPressEvent(QKeyEvent *evento); //Metodo de entrada por teclado


};
#endif // MAINWINDOW_H
