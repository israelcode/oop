#ifndef STACK_ITEM_H
#define STACK_ITEM_H

#include <memory>

template <class T> class StackItem
{
public:
	StackItem(const std::shared_ptr<T>& item);

	std::shared_ptr<StackItem<T>> SetNext(std::shared_ptr<StackItem>& m_next);
	
	std::shared_ptr<StackItem<T>> GetNext();
	std::shared_ptr<T> getFigure() const;

private:
	std::shared_ptr<T> m_item;
	std::shared_ptr<StackItem<T>> m_next;
};

#include "stack_item_impl.cpp"

#endif
