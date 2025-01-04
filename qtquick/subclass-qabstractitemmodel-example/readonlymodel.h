#ifndef READONLYMODEL_H
#define READONLYMODEL_H

#include <QAbstractItemModel>
#include "node.h"

class ReadOnlyModel : public QAbstractItemModel
{
public:
    ReadOnlyModel();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Node *m_root;

protected:

    QModelIndex indexForNode(Node *node) const;
    Node *nodeForIndex(const QModelIndex &index) const;
    int rowForNode(Node *node) const;
};

#endif // READONLYMODEL_H
