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
    wall= new paredSolida(0,0,48); //CONTROL
    //scene->addItem(wall);
    wall2= new paredSolida(0,576,48); //CONTROL
    //scene->addItem(wall2);

    for (int i=0;i<=576;i+=48) {
        for (int j=0;j<=1470;j+=48) {
            if (i==0 || i==576 || j==0 || j==1470) {
                paredesSolidas.push_back(new paredSolida(j,i,48));//Dibuja la parte superior e inferior
                scene->addItem(paredesSolidas.back());
            }
            else if(j%96==0 && i%96==0){//Si i y j son multiplo de 96 (intercalados)
                paredesSolidas.push_back(new paredSolida(j,i,48));//Dibuja los bloques solidos de adentro y los extremos derecho e izquierdo
                scene->addItem(paredesSolidas.back());
            }
        }
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

