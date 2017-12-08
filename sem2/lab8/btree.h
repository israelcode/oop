#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include "btree_item.h"
#include "iterator.h"



#include <chrono>
#include <mutex>

template <class T>
class Btree
{
public:
	Btree();
	
	void bstInsert(const std::shared_ptr<T>& figure);


void bstRInsert(const std::shared_ptr<T>& figure);



	void bstRemove(const std::shared_ptr<T>& figure);
	void Insert(const std::shared_ptr<T>& figure);
	
	std::shared_ptr<T> front() const;

	Iterator<BTreeItem<T>, T> begin() const;
	Iterator<BTreeItem<T>, T> end() const;

	void sort();
	void sortParallel();
	
	unsigned int size() const;

	
	template <class B>
	friend std::ostream& operator << (std::ostream& os, const Btree<B>& Btree);
	template <class B>
	void print1(const Btree<B>& btree);

private:
	std::shared_ptr<BTreeItem<T>> m_root;
	void sortHelper(Btree<T>& q, bool isParallel);
	std::future<void> sortParallelHelper(Btree<T>& q);
	unsigned int m_size;
};

#include "btree_impl.cpp"
#endif
