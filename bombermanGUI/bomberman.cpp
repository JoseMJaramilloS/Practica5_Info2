#include "bomberman.h"

int bomberman::getPosx() const
{
    return posx;
}

int bomberman::getPosy() const
{
    return posy;
}

bomberman::bomberman()
{
    this->posx=48;
    this->posy=48;
    this->lado=48;
    this->vel=8;
    rectx= QRectF(lado/2,0,lado/2+1,lado); //rectangulo de prediccion
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
    painter->setPen(Qt::red);//prediccion
    painter->drawRect(rectx);
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
