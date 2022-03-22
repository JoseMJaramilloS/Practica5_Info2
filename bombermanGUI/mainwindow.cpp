#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer; //inicializacion de reloj
    connect(timer, SIGNAL(timeout()),this,SLOT(Actualizar()));
    timer->start(1000); //Cada que pase un segundo, se ejecuta actualizar

    timerBomba = new QTimer; //inicializacion de reloj
    connect(timerBomba, SIGNAL(timeout()),this,SLOT(explotarBomba()));

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
            else if (i+j>144 && rand()%3==1) {//Genera los ladrillos de forma pseudo-aleatoria (y deja espacio para spawnear personaje)
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

void MainWindow::Actualizar()
{
    ui->lcdNumber->display(tiempoJuego);
    tiempoJuego--;
    if (tiempoJuego==0) {
        timer->stop(); //se debe detener el juego
    }

}

void MainWindow::explotarBomba()
{
    tiempoBomba++;
    if (tiempoBomba==3) {
        scene->removeItem(bomba0); //se quita el objeto de la escena
        delete bomba0;
        timerBomba->stop(); //se detiene el reloj
        tiempoBomba=0; //se reinicia el contador
        this->bombaActive=false; //la bomba ya no esta activa
    }
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if (evento->key()==Qt::Key_W) {//Mover arriba
        if(!evaluarColision())
            bomberman0->moverArriba();
        else
            bomberman0->moverAbajo();
            //bomberman0->moverArriba(0);
    }

    else if (evento->key()==Qt::Key_S) {//Mover abajo
        if(!evaluarColision())
            bomberman0->moverAbajo();
        else
            bomberman0->moverArriba();
            //bomberman0->moverAbajo(0);
    }

    else if (evento->key()==Qt::Key_A) {//Mover izquierda
        if(!evaluarColision())
            bomberman0->moverIzquierda();
        else
            bomberman0->moverDerecha();
    }

    else if (evento->key()==Qt::Key_D) {//Mover derecha
        if(!evaluarColision())
            bomberman0->moverDerecha();
        else
            bomberman0->moverIzquierda();
    }


    else if (evento->key()==Qt::Key_I && this->bombaActive==false) { //bombaActive permite poner solo una bomba a la vez
        bomba0 = new bomba(bomberman0->getPosx(),bomberman0->getPosy(),48);
        scene->addItem(bomba0);
        timerBomba->start(1000); //Cada que pase un segundo, se ejecuta explotarBomba
        this->bombaActive=true;
    }
}

