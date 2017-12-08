//#include <iostream> 

template <class T>
BTreeItem<T>::BTreeItem(const std::shared_ptr<T>& figure)
{
 m_left = nullptr;
 m_right = nullptr;
 m_figure = figure;
}

template <class T>
bool BTreeItem<T>::operator == (const BTreeItem<T>& other) const
{
	return getFigure() == other.getFigure();
}

template <class T>
void BTreeItem<T>::setLeft(std::shared_ptr<BTreeItem<T>> left)
{
m_left=left;
}

template <class T>
void BTreeItem<T>::setRight(std::shared_ptr<BTreeItem<T>> right)
{
m_right=right;
}

template <class T>
std::shared_ptr<BTreeItem<T>> BTreeItem<T>::getLeft()
{
return m_left;
}

template <class T>
std::shared_ptr<BTreeItem<T>> BTreeItem<T>::getRight()
{
return m_right;
}

template <class T> 
std::shared_ptr<T> BTreeItem<T>::getFigure() const
{
return m_figure;
}

template <class B>
std::ostream& operator << (std::ostream& os, const BTreeItem<B>& obj) {
    os << "[" << *obj.m_figure << "]" << std::endl;
    return os;
}
