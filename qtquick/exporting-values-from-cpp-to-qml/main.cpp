#include <QColor>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    // Passed a QString, QSize, and QColor to QML.
    // The root context is the global namespace for the application.
    engine.rootContext()->setContextProperty("_aString", QString("This is a string"));
    engine.rootContext()->setContextProperty("_aSize", QSize(800, 600));
    engine.rootContext()->setContextProperty("_background", QColor(Qt::gray));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("exporting-values-from-cpp-to-qml", "Main");

    return app.exec();
}
