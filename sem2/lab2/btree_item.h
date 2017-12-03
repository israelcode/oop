#ifndef BTREE_ITEM_H
#define BTREE_ITEM_H

#include "square.h"

class BTreeItem
{
public:
BTreeItem(const Square& square);
friend std::ostream& operator << (std::ostream& os, const BTreeItem& obj);


void setLeft(BTreeItem* left); 
void setRight(BTreeItem* right);
BTreeItem* getLeft();
BTreeItem* getRight();
Square getSquare() const;
virtual ~BTreeItem ();


private:
Square m_square;
BTreeItem* m_left;
BTreeItem* m_right;
};

#endif

