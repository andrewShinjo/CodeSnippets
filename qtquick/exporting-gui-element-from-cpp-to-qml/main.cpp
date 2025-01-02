#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "./ellipseitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<EllipseItem>("Shapes", 1, 0, "Ellipse");

    QQmlApplicationEngine engine;

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("exporting-gui-element-from-cpp-to-qml", "Main");

    return app.exec();
}
