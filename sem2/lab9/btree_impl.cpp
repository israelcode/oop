template <class T>
std::shared_ptr<T> Btree<T>::front() const
{
	return m_root->getFigure();
}

template <class T>
unsigned int Btree<T>::size() const
{
	return m_size;
}

template <class T>
Btree<T>::Btree()
{
m_root=nullptr;
m_size=0;
}

template <class T>
Iterator<BTreeItem<T>, T> Btree<T>::begin() const
{
    return Iterator<BTreeItem<T>, T>(m_root);
}

template <class T>
Iterator<BTreeItem<T>, T> Btree<T>::end() const
{
    return Iterator<BTreeItem<T>, T>(nullptr);
}


template <class T>
void insert_helper(std::shared_ptr<BTreeItem<T>> m_root,const std::shared_ptr<T>& figure)
{
	std::shared_ptr<BTreeItem<T>> node = m_root;
		
		if(*figure == *(node->getFigure())){ std::cout<<*figure<<"\n"; std::cout<<*(node->getFigure())<<"\n"; std::cout<<"БЫЛО"<<"\n";}
		else{
		if(*figure < *(node->getFigure())) {
			if(node->getLeft()==nullptr)
				{
				//std::cout<<"INSERT_LEFT";
				std::shared_ptr<BTreeItem<T>> newl=std::make_shared<BTreeItem<T>>(figure);
				node->setLeft(newl);
				}
			else
				{
				std::shared_ptr<BTreeItem<T>> left = node->getLeft();
				insert_helper(left,figure);
				}
			} 
		else if(*figure > *(node->getFigure()))  {
			if(node->getRight()==nullptr)
				{
				//std::cout<<"INSERT_RIGHT";
				std::shared_ptr<BTreeItem<T>> newr=std::make_shared<BTreeItem<T>>(figure);
				node->setRight(newr);
				}
			else
				{
				std::shared_ptr<BTreeItem<T>> right = node->getRight();
				insert_helper(right,figure);
				}
			}				
				
}
}

template <class T>
void Btree<T>::bstInsert(const std::shared_ptr<T>& figure)
{
if(m_root==nullptr)
	{
	m_root = std::make_shared<BTreeItem<T>>(figure);//std::cout<<"INSERT_ROOT";
	}
else 
{insert_helper(m_root,figure);
++m_size;
}

}


template <class T>
void remove_helper(std::shared_ptr<BTreeItem<T>> & item, const std::shared_ptr<T>& figure)
{
 
    std::shared_ptr<BTreeItem<T>> repl = nullptr, parent = nullptr, tmp = item;
    while (tmp != nullptr && !(*(tmp->getFigure()) == *figure))
    {
        parent = tmp;
 
        if (*figure < *(tmp->getFigure()))
        {
            tmp = tmp->getLeft();
        }
        else
        {
            tmp = tmp->getRight();
        }
    }
 
    if (tmp == nullptr)
    {
        return;
    }
 
 
 
    if (tmp->getLeft() != nullptr && tmp->getRight() == nullptr)
    {
        if (parent != nullptr)
        {
            if (parent->getLeft() == tmp)
                parent->setLeft(tmp->getLeft());
            else
                parent->setRight(tmp->getRight());
        }
        else
            item = tmp->getLeft();
 
    }
    else if (tmp->getLeft() == nullptr && tmp->getRight() != nullptr)
    {
        if (parent != nullptr)
        {
            if (parent->getLeft() == tmp)
                parent->setLeft(tmp->getLeft());
            else
                parent->setRight(tmp->getRight());
        }
        else
            item = tmp->getRight();
 
    }
    else if (tmp->getLeft() != nullptr && tmp->getRight() != nullptr)
    {
        repl = tmp->getRight();
 
        if (repl->getLeft() == nullptr) {
            tmp->setRight(repl->getRight());
        }
        else
        {
            while (repl->getLeft() != nullptr)
            {
                parent = repl;
                repl = repl->getLeft();
            }
 
            parent->setLeft(repl->getRight());
        }
        *(tmp->getFigure()) = *(repl->getFigure());
 
    }
    else
    {
        if (parent != nullptr)
        {
            if (parent->getLeft() == tmp)
                parent->setLeft(nullptr);
            else
                parent->setRight(nullptr);
        }
        else
            item = nullptr;
    }
 
    return;
}
 
template <class T>
void Btree<T>::bstRemove(const std::shared_ptr<T>& figure)
{
    remove_helper(m_root, figure);
	--m_size;
}

template <class T>
void print2(const std::shared_ptr<BTreeItem<T>> &node)
{
    if(node == nullptr) return;
    print2(node->getLeft());
    std::cout << *(node->getFigure())<< std::endl;
    print2(node->getRight());
}

template <class B>
std::ostream& operator<<(std::ostream& os, const Btree<B> &btree)
{
std::shared_ptr<BTreeItem<B>> item=btree.m_root;
print2(item);
return os;
}


