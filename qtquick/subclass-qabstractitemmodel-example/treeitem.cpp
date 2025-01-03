#include "treeitem.h"

TreeItem::TreeItem(QString data, TreeItem *parentItem)
    : m_itemData(data), m_parentItem(parentItem)
{

}


void TreeItem::appendChild(std::unique_ptr<TreeItem> &&child)
{
    m_childItems.push_back(std::move(child));
}



TreeItem *TreeItem::child(int row)
{
    if(row >= m_itemData.size())
    {
        return nullptr;
    }

    return m_childItems.at(row).get();
}



int TreeItem::childCount() const
{
    return int(m_childItems.size());
}



int TreeItem::columnCount() const
{
    return 1;
}


QString TreeItem::data() const
{
    return m_itemData;
}

// Gets the item's location within its parent's children list.
int TreeItem::row() const
{

    bool thisHasParent = (m_parentItem == nullptr);

    if(thisHasParent)
    {
        return 0;
    }

    const auto it = std::find_if(
        m_parentItem->m_childItems.cbegin(),
        m_parentItem->m_childItems.cend(),
        [this] (const std::unique_ptr<TreeItem> &treeItem)
        {
            return treeItem.get() == this;
        }
    );

    bool thisFoundInParentsChildList = it != m_parentItem->m_childItems.cend();

    if(thisFoundInParentsChildList)
    {
        return std::distance(m_parentItem->m_childItems.cbegin(), it);
    }

    // this should be unreachable.
    return -1;
}



TreeItem* TreeItem::parentItem()
{
    return m_parentItem;
}

