#ifndef INSERTREMOVEMODEL_H
#define INSERTREMOVEMODEL_H

#include "editablemodel.h"

class InsertRemoveModel : public EditableModel
{
public:
    InsertRemoveModel();

    void insertNode(Node *parentNode, int pos, Node *node);
    void removeNode(Node *node);
};

#endif // INSERTREMOVEMODEL_H
