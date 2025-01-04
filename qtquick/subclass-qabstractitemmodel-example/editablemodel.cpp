#include "editablemodel.h"

EditableModel::EditableModel() {}

// Sets the role data for the item at index to value.
// Returns true if successful; otherwise returns false.
// The dataChanged() signal should be emitted if the data was successfully set.
bool EditableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid() && role == Qt::EditRole)
    {
        Node *node = nodeForIndex(index);
        node->text = value.toString();
        QModelIndex topLeft = index;
        QModelIndex bottomRight = index;
        emit dataChanged(topLeft, bottomRight);
        return true;
    }

    return false;
}

// Returns the item flags for the given index.
Qt::ItemFlags EditableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags defaultFlags = ReadOnlyModel::flags(index);

    if(index.isValid())
    {
        return Qt::ItemIsEditable | defaultFlags;
    }

    return defaultFlags;
}
