#include "paredladrillo.h"

paredLadrillo::paredLadrillo()
{
    this->posx=0;
    this->posy=0;
    this->lado=64;
    setPos(posx,posy);
}

paredLadrillo::paredLadrillo(int x, int y, int lado)
{
    this->posx=x;
    this->posy=y;
    this->lado=lado;
    setPos(posx,posy);
}

QRectF paredLadrillo::boundingRect() const
{
    return QRectF(0,0,lado,lado);
}

void paredLadrillo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pxMap(":/images/ladrillo.png");
    painter->drawPixmap(boundingRect(),pxMap,pxMap.rect());
}
