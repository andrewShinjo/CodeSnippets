#include "readonlymodel.h"

ReadOnlyModel::ReadOnlyModel()
//    : m_root(new Node("Root"))
{
    m_root = new Node("Root");
    Node *child = new Node("Child 1", m_root);
    m_root->children.push_back(child);
}

QModelIndex ReadOnlyModel::index(int row, int column, const QModelIndex &parent) const
{
    if(hasIndex(row, column, parent))
    {
        Node *parentNode = nodeForIndex(parent);
        auto iterator = parentNode->children.begin();
        std::advance(iterator, row);
        return createIndex(row, column, *iterator);
    }

    // QModelIndex() represents an invalid index.
    // The root node doesn't have a valid index by design.
    return QModelIndex();
}

QModelIndex ReadOnlyModel::parent(const QModelIndex &index) const
{
    Node *node = nodeForIndex(index);
    Node *parentNode = node->parent;

    if(parentNode == m_root)
    {
        return QModelIndex();
    }

    int row = rowForNode(parentNode);
    int column = 0;
    return createIndex(row, column, parentNode);
}

int ReadOnlyModel::rowCount(const QModelIndex &parent) const
{
    Node *parentNode = nodeForIndex(parent);
    return parentNode->children.size();
}

int ReadOnlyModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

// Returns the data stored under the given role for the item referred to by the index.
QVariant ReadOnlyModel::data(const QModelIndex &index, int role) const
{
    if(index.isValid() && role == Qt::DisplayRole)
    {
        Node *node = nodeForIndex(index);
        return node->data();
    }

    return QVariant(); // Returns an invalid variant.
}

QModelIndex ReadOnlyModel::indexForNode(Node *node) const
{
    if(node == m_root)
    {
        // QModelIndex() represents an invalid index.
        // The root node doesn't have a valid index by design.
        return QModelIndex();
    }

    int row = rowForNode(node);
    int column = 0;
    return createIndex(row, column, node);
}

Node *ReadOnlyModel::nodeForIndex(const QModelIndex &index) const
{
    if(!index.isValid())
    {   // If the index is invalid, then we are returning the root node.
        return m_root;
    }

    return static_cast<Node*>(index.internalPointer());
}

int ReadOnlyModel::rowForNode(Node *node) const
{
    std::list<Node*> children = node->parent->children;
    auto iterator = std::find(children.begin(), children.end(), node);
    int row = std::distance(children.begin(), iterator);
    return row;
}
