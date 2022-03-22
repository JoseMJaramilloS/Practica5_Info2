#ifndef BOMBA_H
#define BOMBA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class bomba : public QGraphicsItem
{
    int posx;
    int posy;
    int lado;

private slots:


public:
    bomba();
    ~bomba();
    bomba(int x, int  y, int lado);
    virtual QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // BOMBA_H
