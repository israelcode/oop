#include "btree.h"
#include "ctype.h"
#include <iostream>

Btree::Btree()
{
m_root=nullptr;
}

void insert_helper(std::shared_ptr<BTreeItem> m_root,const std::shared_ptr<Figure>& figure)
{
	std::shared_ptr<BTreeItem> node = m_root;
		
		if(*figure == *(node->getFigure())){ std::cout<<*figure<<"\n"; std::cout<<*(node->getFigure())<<"\n"; std::cout<<"БЫЛО"<<"\n";}
		else{
		if(*figure < *(node->getFigure())) {
			if(node->getLeft()==nullptr)
				{
				std::shared_ptr<BTreeItem> newl=std::make_shared<BTreeItem>(figure);
				node->setLeft(newl);
				}
			else
				{
				std::shared_ptr<BTreeItem> left = node->getLeft();
				insert_helper(left,figure);
				}
			} 
		else if(*figure > *(node->getFigure()))  {
			if(node->getRight()==nullptr)
				{
				std::shared_ptr<BTreeItem> newr=std::make_shared<BTreeItem>(figure);
				node->setRight(newr);
				}
			else
				{
				std::shared_ptr<BTreeItem> right = node->getRight();
				insert_helper(right,figure);
				}
			}				
				
}
}


void Btree::bstInsert(const std::shared_ptr<Figure>& figure)
{
if(m_root==nullptr)
	{
	m_root = std::make_shared<BTreeItem>(figure);
	}
else 
{insert_helper(m_root,figure);}

}



void remove_helper(std::shared_ptr<BTreeItem> & item, const std::shared_ptr<Figure>& figure)
{
 
    std::shared_ptr<BTreeItem> repl = nullptr, parent = nullptr, tmp = item;
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
 
 
void Btree::bstRemove(const std::shared_ptr<Figure>& figure)
{
    remove_helper(m_root, figure);
}


void print2(const std::shared_ptr<BTreeItem> &node)
{
    if(node == nullptr) return;
    print2(node->getLeft());
    std::cout << *(node->getFigure())<< std::endl;
    print2(node->getRight());
}

std::ostream& operator<<(std::ostream & os, const Btree &btree)
{
	std::shared_ptr<BTreeItem> item=btree.m_root;
	print2(item);
	return os;
}


