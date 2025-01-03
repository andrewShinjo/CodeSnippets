#include "treemodel.h"


TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = std::make_unique<TreeItem>(TreeItem("Root node"));

    std::unique_ptr<TreeItem> child1 = std::make_unique<TreeItem>(TreeItem("Child 1", rootItem.get()));
    std::unique_ptr<TreeItem> child11 = std::make_unique<TreeItem>(TreeItem("Child 1.1", child1.get()));
    std::unique_ptr<TreeItem> child12 = std::make_unique<TreeItem>(TreeItem("Child 1.2", child1.get()));
    std::unique_ptr<TreeItem> child13 = std::make_unique<TreeItem>(TreeItem("Child 1.3", child1.get()));
    std::unique_ptr<TreeItem> child14 = std::make_unique<TreeItem>(TreeItem("Child 1.4", child1.get()));

    child1.get()->appendChild(std::move(child11));
    child1.get()->appendChild(std::move(child12));
    child1.get()->appendChild(std::move(child13));
    child1.get()->appendChild(std::move(child14));
    rootItem.get()->appendChild(std::move(child1));
}

TreeModel::~TreeModel() = default;

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if(!hasIndex(row, column, parent))
    {
        return {};
    }

    TreeItem *parentItem = parent.isValid() ?
        static_cast<TreeItem*>(parent.internalPointer()) : rootItem.get();

    if(auto *childItem = parentItem->child(row))
    {
        return createIndex(row, column, childItem);
    }

    return {};
}



QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return {};
    }

    auto *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();

    return parentItem != rootItem.get() ?
        createIndex(parentItem->row(), 0, parentItem) : QModelIndex{};
}



int TreeModel::rowCount(const QModelIndex &parent) const
{
    const TreeItem *parentItem = parent.isValid() ?
        static_cast<const TreeItem*>(parent.internalPointer()) : rootItem.get();
    return parentItem->childCount();
}



int TreeModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}



QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid() || role != Qt::DisplayRole)
    {
        return {};
    }

    const auto *item = static_cast<const TreeItem*>(index.internalPointer());
    return item->data();
}



Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    return index.isValid() ?
               QAbstractItemModel::flags(index) : Qt::ItemFlags(Qt::NoItemFlags);
}
