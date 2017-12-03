#ifndef BTREE_H
#define BTREE_H

#include "btree_item.h"

class Btree
{
public:
	Btree();
	virtual ~Btree();
	
	void bstInsert(const Square& square);//!
	void bstRemove(const Square& square);//!

	friend std::ostream& operator << (std::ostream& os, const Btree& Btree); //!
	
private:
	BTreeItem* m_root;
};

#endif
