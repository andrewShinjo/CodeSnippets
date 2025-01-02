#include "hellocomponent.h"

HelloComponent::HelloComponent(QObject *parent)
    : QObject{parent}
{}

QString HelloComponent::sayHello()
{
    return "Hello";
}
