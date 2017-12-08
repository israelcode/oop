template <class N, class T>
Iterator<N, T>::Iterator(const std::shared_ptr<N>& item)
{
	m_item = m_item->GoFarLeft(item);
	m_item = item;
}

template <class N, class T>
std::shared_ptr<N> Iterator<N, T>::getItem() const
{
	return m_item;
}

template <class N, class T>
std::shared_ptr<T> Iterator<N, T>::operator * ()
{
	return m_item->getItem();
}

template <class N, class T> 
std::shared_ptr<T> Iterator<N, T>::operator -> ()
{
	return m_item->getFigure();
}


template <class N, class T>
Iterator<N, T> Iterator<N, T>::left ()
{
	m_item = m_item->getLeft();

	return *this;
}
template <class N, class T>
Iterator<N, T> Iterator<N, T>::right ()
{
	m_item = m_item->getRight();

	return *this;
}



template <class N, class T>
Iterator<N, T> Iterator<N, T>::operator ++ ()
{
	BTreeItem<T> temp=m_item;
	m_item =m_item->nextInorder();
        return *temp;
	return m_item;
}


template <class N, class T>
bool Iterator<N, T>::operator == (const Iterator& other) const
{
	return m_item == other.m_item;
}

template <class N, class T>
bool Iterator<N, T>::operator != (const Iterator& other) const
{
	return !(*this == other);
}
