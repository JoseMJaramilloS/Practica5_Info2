#ifndef BOMBERMAN_H
#define BOMBERMAN_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class bomberman : public QGraphicsItem
{
    //Atributos
    int posx;
    int posy;
    int lado;
    int vel;
public:
    //Constructores
    bomberman();
    bomberman(int x, int y, int lado, int vel);

    //Metodos
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void moverArriba();
    void moverAbajo();
    void moverIzquierda();
    void moverDerecha();
};

#endif // BOMBERMAN_H
