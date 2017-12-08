#ifndef BTREE_ITEM_H
#define BTREE_ITEM_H

#include <memory>

template <class T>
class BTreeItem
{
public:
	
	BTreeItem(const std::shared_ptr<T>& figure);
	template <class B>
	friend std::ostream& operator << (std::ostream& os, const BTreeItem<B>& obj);
	bool operator == (const BTreeItem<T>& other) const;

	void setLeft(std::shared_ptr<BTreeItem<T>> left); 
	void setRight(std::shared_ptr<BTreeItem<T>> right);
	std::shared_ptr<BTreeItem<T>> getLeft();
	std::shared_ptr<BTreeItem<T>> getRight();
	std::shared_ptr<T> getFigure() const;	



private:
std::shared_ptr<T> m_figure;
std::shared_ptr<BTreeItem<T>> m_left;
std::shared_ptr<BTreeItem<T>> m_right;
};

#include "btree_item_impl.cpp"
#endif

