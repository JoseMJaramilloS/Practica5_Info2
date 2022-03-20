#ifndef PAREDLADRILLO_H
#define PAREDLADRILLO_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class paredLadrillo : public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
public:
    paredLadrillo();
    paredLadrillo(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // PAREDLADRILLO_H
