#include "paredsolida.h"

paredSolida::paredSolida()
{
    this->posx=0;
    this->posy=0;
    this->lado=64;
    setPos(posx,posy);
}

paredSolida::paredSolida(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF paredSolida::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void paredSolida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/images/solid.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
