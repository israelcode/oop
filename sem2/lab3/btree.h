#ifndef BTREE_H
#define BTREE_H

#include "btree_item.h"

class Btree
{
public:
	Btree();
	
	void bstInsert(const std::shared_ptr<Figure>& figure);
	void bstRemove(const std::shared_ptr<Figure>& figure);
	void Insert(const std::shared_ptr<Figure>& figure);
	void print1(const Btree& btree);

	friend std::ostream& operator << (std::ostream& os, const Btree& Btree);

private:
	std::shared_ptr<BTreeItem> m_root;
};

#endif
