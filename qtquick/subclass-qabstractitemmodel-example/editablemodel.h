#ifndef EDITABLEMODEL_H
#define EDITABLEMODEL_H

#include "readonlymodel.h"

class EditableModel : public ReadOnlyModel
{
public:

    EditableModel();
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

};

#endif // EDITABLEMODEL_H
