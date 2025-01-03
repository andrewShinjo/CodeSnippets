#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStandardItemModel>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    QStandardItemModel model;
    QStandardItem *parentItem = model.invisibleRootItem();

    for(int i=0; i < 5; i++)
    {
        QStandardItem *item = new QStandardItem(QString("item %0").arg(i));
        parentItem->appendRow(item);
        parentItem = item;
    }

    engine.rootContext()->setContextProperty("_treeModel", &model);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("treeview-minimal-example", "Main");

    return app.exec();
}
