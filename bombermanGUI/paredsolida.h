#ifndef PAREDSOLIDA_H
#define PAREDSOLIDA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class paredSolida : public QGraphicsItem
{
    int posx;
    int posy;
    int lado;
public:
    paredSolida();
    paredSolida(int x, int y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // PAREDSOLIDA_H
