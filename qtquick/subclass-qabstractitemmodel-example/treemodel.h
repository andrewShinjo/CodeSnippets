#ifndef TREEMODEL_H
#define TREEMODEL_H

#include <QAbstractItemModel>
#include "./treeitem.h"

// Defines the standard interface that item models must use to be able to interoperate with
// other components in the model/view architecture. To implement a read-only model, we need to
// implement the following functions:
// index()
// parent()
// rowCount()
// [DONE] columnCount()
// data()

// QModelIndex is used as an index into item models derived from QAbstractItemModel.
// Each index is located in a given row and column, any may have a parent index.
// An item is a root if it's model index has no parent index.

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:

    TreeModel(QObject *parent = nullptr);
    ~TreeModel() override;
    QModelIndex index(int row, int column, const QModelIndex &parent = {}) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = {}) const override;
    int columnCount(const QModelIndex &parent = {}) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

private:

    std::unique_ptr<TreeItem> rootItem;
};

#endif // TREEMODEL_H
