#ifndef NODE_H
#define NODE_H

#include <QVariant>

class Node
{
public:

    Node(const QString &text = "No data", Node *parent = nullptr);
    QVariant data() const;

    QString text;
    Node *parent;
    std::list<Node*> children;
};

#endif // NODE_H
