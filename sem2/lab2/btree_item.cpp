#include "btree_item.h"
#include <iostream>


BTreeItem::BTreeItem(const Square& square)
{
 m_left = nullptr;
 m_right = nullptr;
 m_square = square;
}

void BTreeItem::setLeft(BTreeItem* left)
{
m_left=left;
}

void BTreeItem::setRight(BTreeItem* right)
{
m_right=right;
}

BTreeItem* BTreeItem::getLeft()
{
return m_left;
}

BTreeItem* BTreeItem::getRight()
{
return m_right;
}
 
Square BTreeItem::getSquare() const
{
return m_square;
}

BTreeItem::~BTreeItem()
{
delete m_left;
delete m_right;
}

std::ostream& operator << (std::ostream& os, const BTreeItem& obj) {
    os << "[" << obj.m_square << "]" << std::endl;
    return os;
}
