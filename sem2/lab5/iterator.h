#ifndef ITERATOR_H
#define ITERATOR_H

template <class N, class T>
class Iterator
{
public:
	Iterator(const std::shared_ptr<N>& item);
	std::shared_ptr<T> operator * ();
	std::shared_ptr<T> operator -> ();
	Iterator left ();
	Iterator right ();
	Iterator operator ++ ();
	bool operator == (const Iterator& other) const;
	bool operator != (const Iterator& other) const;
	
private:
	std::shared_ptr<N> m_item;
	 void nextInorder()
    		{
        	if (m_item->element == NULL)return;
        	else {
            	nextInorder(m_item->left);
            	nextInorder(m_item->element);
            	nextInorder(m_item->right);
        }
    }

};

#include "iterator_impl.cpp"

#endif
