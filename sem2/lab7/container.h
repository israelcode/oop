#ifndef CONTAINTER_H
#define CONTAINTER_H

#include <memory>
#include <cstring>
#include "btree.h"
#include "stack.h"
#include "criteria.h"

template <class T>
class Container
{
public:
	void add(const std::shared_ptr<T>& item);
	void erase(const Criteria<T>& criteria);
Stack<Figure> stack2;
	template <class B>
	friend std::ostream& operator << (std::ostream& os, const Container<B>& container);

private:
	Btree<Stack<T>> m_container;
};

#include "container_impl.cpp"

#endif
