#include "insertremovemodel.h"

InsertRemoveModel::InsertRemoveModel()
{
    m_root = new Node("Root");
}

void InsertRemoveModel::insertNode(Node *parentNode, int pos, Node *node)
{
    qDebug() << "InsertRemoveModel::insertNode";

    const QModelIndex parent = indexForNode(parentNode);
    int firstRow = pos;
    int lastRow = pos;

    beginInsertRows(parent, firstRow, lastRow);
    auto iterator = parentNode->children.begin();
    std::advance(iterator, pos);
    parentNode->children.insert(iterator, node);
    endInsertRows();

    qDebug() << "children.size() = " << parentNode->children.size();
}

void InsertRemoveModel::removeNode(Node *node)
{
    Node *parentNode = node->parent;
    const QModelIndex parent = indexForNode(parentNode);
    int pos = rowForNode(node);
    int firstRow = pos;
    int lastRow = pos;

    beginRemoveRows(parent, firstRow, lastRow);
    std::list<Node*> children = parentNode->children;
    auto iterator = children.begin();
    std::advance(iterator, pos);
    children.erase(iterator);
    endRemoveRows();
}
