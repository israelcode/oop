//#include "TStack.h"
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
	return getItem() == other.getItem();
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
std::shared_ptr<T> BTreeItem<T>::getItem() const
{
return m_figure;
}

template <class B>
std::ostream& operator << (std::ostream& os, const BTreeItem<B>& obj) {
    os << "[" << *obj.m_figure << "]" << std::endl;
    return os;
}

template <typename R>
shared_ptr<BTreeItem<R>> BTreeItem<R>::GoFarLeft(shared_ptr<BTreeItem<R>> current) {
    if (current == nullptr) {
        return nullptr;
    }
    while (current->getLeft() != nullptr) {
        stackOfBTreeItem.Push(current);
        current = current->getLeft();
    }
    return current;
};

template <typename R>
shared_ptr<BTreeItem<R>> BTreeItem<R>::GetNext(){
    shared_ptr<BTreeItem<R>> temp;
    if (this->getRight() != nullptr) {
        temp = GoFarLeft(this->getRight());
    }
    else if(!stackOfBTreeItem.IsEmpty()){
        temp = stackOfBTreeItem.Pop();
    }
    else {
        temp = nullptr;
    }
    return temp;
};
