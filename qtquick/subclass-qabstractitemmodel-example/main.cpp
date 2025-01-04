#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "readonlymodel.h"
#include "insertremovemodel.h"
#include "node.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    InsertRemoveModel model;

    Node *child0 = new Node("Child 0", model.m_root);
    Node *child1 = new Node("Child 1", model.m_root);
    Node *child2 = new Node("Child 2", model.m_root);
    Node *child3 = new Node("Child 3", model.m_root);
    Node *child4 = new Node("Child 4", model.m_root);

    Node *child00 = new Node("Child 0.0", child0);

    model.insertNode(model.m_root, 0, child0);
    model.insertNode(model.m_root, 1, child1);
    model.insertNode(model.m_root, 2, child2);
    model.insertNode(model.m_root, 3, child3);
    model.insertNode(model.m_root, 4, child4);

    model.insertNode(child0, 0, child00);


    engine.rootContext()->setContextProperty("_model", &model);


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("subclass-qabstractitemmodel-example", "Main");

    return app.exec();
}
