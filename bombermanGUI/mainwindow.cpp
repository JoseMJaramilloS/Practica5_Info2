#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1488,624);//1488,624     

    //GENERACION DE BLOQUES
    for (int i=0;i<=576;i+=48) {
        for (int j=0;j<=1440;j+=48) {
            if (i==0 || i==576 || j==0 || j==1440) {//Si esta en los extremos
                paredesSolidas.push_back(new paredSolida(j,i,48));//Dibuja los bloques de los bordes
                scene->addItem(paredesSolidas.back());
            }
            else if(j%96==0 && i%96==0){//Si i y j son multiplo de 96 (intercalados)
                paredesSolidas.push_back(new paredSolida(j,i,48));//Dibuja los bloques solidos de adentro
                scene->addItem(paredesSolidas.back());
            }
            else if (i+j>144 && rand()%3==1) {//Genera los ladrillos de forma pseudo-aleatoria
                //se puede cambiar la probabilidad de aparacicion modificando el valor del modulo
                paredesLadrillos.push_back(new paredLadrillo(j,i,48));
                scene->addItem(paredesLadrillos.back());
            }
        }
    }

    bomberman0 = new bomberman();
    scene->addItem(bomberman0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::evaluarColision()
{
    for (itSol=paredesSolidas.begin();itSol!=paredesSolidas.end();itSol++) {
        if ((*itSol)->collidesWithItem(bomberman0)) {
            return true;
        }
    }
    for (itLad=paredesLadrillos.begin();itLad!=paredesLadrillos.end();itLad++) {
        if ((*itLad)->collidesWithItem(bomberman0)) {
            return true;
        }
    }
    return false;

}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key()==Qt::Key_W) {//Mover arriba
        bomberman0->moverArriba();
    }

    else if (evento->key()==Qt::Key_S) {//Mover abajo
        bomberman0->moverAbajo();
    }

    else if (evento->key()==Qt::Key_A) {//Mover izquierda
        bomberman0->moverIzquierda();
    }

    else if (evento->key()==Qt::Key_D) {//Mover derecha
        bomberman0->moverDerecha();
    }

}

