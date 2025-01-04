#include "node.h"

Node::Node(const QString &text, Node *parent)
    : text(text), parent(parent)
{

}

QVariant Node::data() const
{
    return QVariant::fromValue(text);
}
