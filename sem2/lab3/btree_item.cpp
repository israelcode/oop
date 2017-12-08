#include "btree_item.h"
#include <iostream> 

BTreeItem::BTreeItem(const std::shared_ptr<Figure>& figure)
{
 m_left = nullptr;
 m_right = nullptr;
 m_figure = figure;
}

bool BTreeItem::operator == (const BTreeItem& other) const
{
	return getFigure() == other.getFigure();
}

void BTreeItem::setLeft(std::shared_ptr<BTreeItem> left)
{
m_left=left;
}

void BTreeItem::setRight(std::shared_ptr<BTreeItem> right)
{
m_right=right;
}

std::shared_ptr<BTreeItem> BTreeItem::getLeft()
{
return m_left;
}

std::shared_ptr<BTreeItem> BTreeItem::getRight()
{
return m_right;
}
 
std::shared_ptr<Figure> BTreeItem::getFigure() const
{
return m_figure;
}


std::ostream& operator << (std::ostream& os, const BTreeItem& obj) {
    os << "[" << *obj.m_figure << "]" << std::endl;
    return os;
}
