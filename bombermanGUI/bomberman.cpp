#include "bomberman.h"

bomberman::bomberman()
{
    this->posx=48;
    this->posy=48;
    this->lado=48;
    this->vel=6;
    setPos(posx,posy);
}

bomberman::bomberman(int x, int y, int lado, int vel)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    this->vel=vel;
    setPos(posx,posy);
}

QRectF bomberman::boundingRect() const
{
    return QRectF(0,0,48,48);
}

void bomberman::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/images/walking_right1.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}

void bomberman::moverArriba()
{
    this->posy -= vel;
    setPos(posx,posy);
}

void bomberman::moverAbajo()
{
    this->posy += vel;
    setPos(posx,posy);
}

void bomberman::moverIzquierda()
{
    this->posx -= vel;
    setPos(posx,posy);
}

void bomberman::moverDerecha()
{
    this->posx += vel;
    setPos(posx,posy);
}
