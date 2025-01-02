#ifndef HELLOCOMPONENT_H
#define HELLOCOMPONENT_H

#include <QObject>
#include <QTimer>

class HelloComponent : public QObject
{
    Q_OBJECT

public:

    explicit HelloComponent(QObject *parent = nullptr);

    Q_INVOKABLE QString sayHello();

signals:

};

#endif // HELLOCOMPONENT_H
