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
    scene->addItem(wall);
    wall2= new paredSolida(0,576,48); //CONTROL
    scene->addItem(wall2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

