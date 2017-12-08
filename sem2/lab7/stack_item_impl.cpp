template <class T>
StackItem<T>::StackItem(const std::shared_ptr<T>& item)
{
	m_item = item;
}



template <class T> std::shared_ptr<StackItem<T>>
StackItem<T>::SetNext(std::shared_ptr<StackItem<T>> &next) {
	std::shared_ptr<StackItem < T>> old = this->m_next;
	this->m_next = next;
	return old;
}


template <class T> std::shared_ptr<StackItem<T>>
StackItem<T>::setNext(){
std::shared_ptr<StackItem < T>> old = this->m_next;
	this->m_next = nullptr;
	return old;
}

template <class T>
std::shared_ptr<StackItem<T>> StackItem<T>::GetNext()
{
	return this->m_next;
}


template <class T>
std::shared_ptr<T> StackItem<T>::getItem() const
{
	return this->m_item;
}

template <class T>
void StackItem<T>::swap(StackItem<T>& other)
{
	m_item.swap(other.m_item);
}
