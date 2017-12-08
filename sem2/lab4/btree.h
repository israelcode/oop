#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include "btree_item.h"

template <class T>
class Btree
{
public:
	Btree();
	
	void bstInsert(const std::shared_ptr<T>& figure);
	void bstRemove(const std::shared_ptr<T>& figure);
	void Insert(const std::shared_ptr<T>& figure);
	

	template <class B>
	friend std::ostream& operator << (std::ostream& os, const Btree<B>& Btree);
	template <class B>
	void print1(const Btree<B>& btree);

private:
	std::shared_ptr<BTreeItem<T>> m_root;
};

#include "btree_impl.cpp"
#endif
