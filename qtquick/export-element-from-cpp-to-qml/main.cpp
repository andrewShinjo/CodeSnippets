#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "hellocomponent.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<HelloComponent>("CustomComponents", 1, 0, "HelloComponent");

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("export-element-from-cpp-to-qml", "Main");

    return app.exec();
}
