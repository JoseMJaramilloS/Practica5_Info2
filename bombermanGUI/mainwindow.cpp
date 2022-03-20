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
                paredesLadrillos.push_back(new paredLadrillo(j,i,48));
                scene->addItem(paredesLadrillos.back());
}
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

