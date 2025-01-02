#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "./user.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    User *currentUser = new User("Alice", 29);

    engine.rootContext()->setContextProperty("_currentUser", currentUser);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("exporting-qobjects-from-cpp-to-qml", "Main");

    return app.exec();
}
