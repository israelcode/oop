#ifndef BTREE_ITEM_H
#define BTREE_ITEM_H

#include <memory>
#include "figure.h"

class BTreeItem
{
public:
	BTreeItem(const std::shared_ptr<Figure>& figure);
	friend std::ostream& operator << (std::ostream& os, const BTreeItem& obj);
	bool operator == (const BTreeItem& other) const;

	void setLeft(std::shared_ptr<BTreeItem> left); 
	void setRight(std::shared_ptr<BTreeItem> right);
	std::shared_ptr<BTreeItem> getLeft();
	std::shared_ptr<BTreeItem> getRight();
	std::shared_ptr<Figure> getFigure() const;	



private:
std::shared_ptr<Figure> m_figure;
std::shared_ptr<BTreeItem> m_left;
std::shared_ptr<BTreeItem> m_right;
};

#endif

