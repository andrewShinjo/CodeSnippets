#include "editabletreemodel.h"

EditableTreeModel::EditableTreeModel(QObject *parent)
    : TreeModel{parent}
{}

Qt::ItemFlags EditableTreeModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::NoItemFlags;
    }

    return Qt::ItemIsEditable | TreeModel::flags(index);
}

bool EditableTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        TreeItem *item =
    }
}

bool EditableTreeModel::insertRows(int row, int count, const QModelIndex &parent)
{
    return true;
}

bool EditableTreeModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return true;
}
