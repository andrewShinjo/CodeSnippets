#ifndef TREEITEM_H
#define TREEITEM_H

#include <QStringList>

class TreeItem
{
public:

    TreeItem(QString data, TreeItem *parentitem = nullptr);
    void appendChild(std::unique_ptr<TreeItem> &&child);
    TreeItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QString data() const;
    int row() const;
    TreeItem* parentItem();

private:

    std::vector<std::unique_ptr<TreeItem>> m_childItems;
    QString m_itemData;
    TreeItem *m_parentItem;

};

#endif // TREEITEM_H
