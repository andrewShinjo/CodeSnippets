#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QPainter>
#include <QQuickPaintedItem>

class EllipseItem : public QQuickPaintedItem
{

    Q_OBJECT

public:
    EllipseItem(QQuickItem *parent = nullptr);
    void paint(QPainter *painter) override;



signals:

private:

};

#endif // ELLIPSEITEM_H
