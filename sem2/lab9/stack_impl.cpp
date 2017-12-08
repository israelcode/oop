template <class T>
Stack<T>::Stack()
{
	head=nullptr;
	m_size=0;
}

template <class T>
Stack<T>::~Stack()
{}


template <class T>
void Stack<T>::Push(const std::shared_ptr<T>& item)
{
	std::shared_ptr<StackItem<T>> other(new StackItem<T>(item));
	other->SetNext(head);
	head=other;
	++m_size;
}

template <class T> std::shared_ptr<T> Stack<T>::Pop() {
	std::shared_ptr<T> result;
	if (head != nullptr) {
		result = head->getFigure();
		head = head->GetNext();
	}
	--m_size;
	return result;
}


template <class T>
unsigned int Stack<T>::size() const
{
	return m_size;
}

template <class T>
Iterator<StackItem<T>, T> Stack<T>::get(unsigned int index) const
{
	if (index >= size())
		return end();

	Iterator<StackItem<T>, T> it = begin();

	while (index > 0)
	{
		++it;
		--index;
	}

	return it;
}

template <class T>
Iterator<StackItem<T>, T> Stack<T>::begin() const
{
	return Iterator<StackItem<T>, T>(head);
}




template <class T>
Iterator<StackItem<T>, T> Stack<T>::end() const
{
	return Iterator<StackItem<T>, T>(nullptr);
}

template <class K>
std::ostream& operator << (std::ostream& os, const Stack<K>& stack)
{
	if (stack.size() == 0)
	{
		os << "================" << std::endl;
		os << "Stack is empty" << std::endl;
	}
	else
		for (std::shared_ptr<K> item : stack)
			item->print();

	return os;
}/**/




template <class T>
std::shared_ptr<T> Stack<T>::front() const
{
	return head->getFigure();
}
