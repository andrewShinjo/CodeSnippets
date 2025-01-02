#include "ellipseitem.h"

EllipseItem::EllipseItem(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{

}

void EllipseItem::paint(QPainter *painter)
{
    painter->setPen(QPen(Qt::black, 2));
    QRect paintRect(0, 0, 200, 100);
    painter->drawEllipse(paintRect);
}
