#ifndef PIECHART_H
#define PIECHART_H

// Makes it possible to use the QPainter API with the QML scene graph.
#include <QtQuick/QQuickPaintedItem>

#include <QColor>

// This class inherits QQUickPaintedItem because we want to override QQuickPaintedItem::paint()
// to perform drawing operations with the QPainter API.
// If we want a class that represents data that's not drawn to the screen,
// then you can inherit from QObject instead.
// If we want to extend the functionality of an existing QObject-based class,
// then we can inherit from that class instead.
// If we want to create a visual item that doesn't perform drawing operations with the QPainter API,
// then we cna subclass QQuickItem instead.
class PieChart : public QQuickPaintedItem
{
    Q_OBJECT

    // The FINAL attribute means the property will not be overridden by a derived class.
    Q_PROPERTY(QString name READ name WRITE setName FINAL)
    Q_PROPERTY(QString color READ color WRITE setColor FINAL)

    // Declares the enclosing type or namespace to be available in QML,
    // using its class or namespace name as the QML element name.
    QML_ELEMENT

public:

    PieChart(QQuickItem *parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    QColor color() const;
    void setColor(const QColor &color);

    void paint(QPainter *painter) override;

private:

    QString m_name;
    QColor m_color;
};

#endif // PIECHART_H
