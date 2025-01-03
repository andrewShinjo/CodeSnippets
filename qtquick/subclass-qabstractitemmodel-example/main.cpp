#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "./treemodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    TreeModel _treeModel;

    engine.rootContext()->setContextProperty("_treeModel", &_treeModel);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("subclass-qabstractitemmodel-example", "Main");

    return app.exec();
}
