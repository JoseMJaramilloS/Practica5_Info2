#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QList> //Para uso de STL listas
#include <cstdlib> //Para generacion de numeros aleatorios
#include <QKeyEvent> //Para controlar por teclado
#include <QTimer> //Para hacer temporizador
#include "paredsolida.h"
#include "paredladrillo.h"
#include "bomberman.h"
#include "bomba.h"

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

private slots:
    void Actualizar(); //se va ejecutar cuando el reloj termine de contar
    void explotarBomba();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList <paredSolida*>paredesSolidas; //Lista de bloques solidos
    QList <paredSolida*>::Iterator itSol;
    QList <paredLadrillo*>paredesLadrillos; //lista de bloques ladrillo
    QList <paredLadrillo*>::Iterator itLad;
    QTimer *timer; //reloj principal
    QTimer *timerBomba; //reloj bomba
    bomberman *bomberman0; //personaje principal
    bomba *bomba0;
    void keyPressEvent(QKeyEvent *evento); //Metodo de entrada por teclado
    int tiempoJuego=300; //contador del tiempo de juego
    int tiempoBomba=0; //contador del tiempo de bomba
    bool bombaActive=false;

};
#endif // MAINWINDOW_H
