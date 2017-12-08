#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stack_item.h"
#include "iterator.h"



template <class T> class Stack
{
public:
	Stack();
	virtual ~Stack();

	void Push(const std::shared_ptr<T>& item);
	std::shared_ptr<T> Pop();
	
	unsigned int size() const;
	bool empty();
	Iterator<StackItem<T>, T> get(unsigned int index) const;

	Iterator<StackItem<T>, T> begin() const;
	Iterator<StackItem<T>, T> end() const;

	template <class K>
	friend std::ostream& operator << (std::ostream& os, const Stack<K>& stack);

private:
	std::shared_ptr<StackItem<T>> head;
	unsigned int m_size;
};

#include "stack_impl.cpp"

#endif
