#include "btree.h"
#include "ctype.h"
Btree::Btree()
{
m_root=nullptr;
}


void destroy_tree(BTreeItem *m_root)
{
  if(m_root!=nullptr)
  {
    destroy_tree(m_root->getLeft());
    destroy_tree(m_root->getRight());
    delete m_root;
  }
}


Btree::~Btree()
{
  destroy_tree(m_root);
}


void insert_helper(BTreeItem **ptr,const Square& value)
{
	
   	if (value<(*ptr)->getSquare())
	{
		if ((*ptr)->getLeft())
		{
		BTreeItem* left = (*ptr)->getLeft();
		insert_helper(&left,value);
		}
		else 
		{		
		BTreeItem* newl= new BTreeItem(value);
		(*ptr)->setLeft(newl);		
		}
	} 
	else if (value>(*ptr)->getSquare())
	{
		if((*ptr)->getRight())
		{
		BTreeItem* right = (*ptr)->getRight();
		insert_helper(&right,value);		
		}
		else
	 	{
		BTreeItem* newr= new BTreeItem(value);
		(*ptr)->setRight(newr);
		}
	}
	else if (value==(*ptr)->getSquare())
	{
		std::cout<<"Было"<<std::endl;
	}
}
 
void Btree::bstInsert(const Square& square)
{
if(m_root==nullptr)
{m_root= new BTreeItem(square);}
else {insert_helper(&m_root,square);}
}


std::ostream& operator<<(std::ostream& os, const Btree& btree) 
{
	BTreeItem *item=btree.m_root;
	
	if (item==nullptr) 	
	{
	os << "================" << std::endl;
	os << "Tree is empty" << std::endl;	
	}
	else 
	{
		BTreeItem *left = item->getLeft();
			if (left) 
			{
		   	os<<*(left);
			}
		os<<(item->getSquare());
		BTreeItem *right = item->getRight();
					
			if (right) 
			{
		   	os<<*(right);
			}
		

	}
	return os;
}

void remove_helper(BTreeItem **item, const Square& square)
{
BTreeItem *repl = nullptr, *parent = nullptr, *tmp = *item;

while (tmp != nullptr && !(tmp->getSquare() == square)) 			
	{
		parent = tmp;

		if (square < tmp->getSquare())
			tmp = tmp->getLeft();
		else
			tmp = tmp->getRight();
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
			*item = tmp->getRight();

		free(tmp);

		tmp = nullptr;
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
			*item = tmp->getRight();

		free(tmp);

		tmp = nullptr;
	}

	else if (tmp->getLeft() != nullptr && tmp->getRight() != nullptr) 
	{
		repl = tmp->getRight();

		if (repl->getLeft() == nullptr){
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
		tmp->getSquare() = repl->getSquare();

		free(repl);

		repl = nullptr;
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
			*item = nullptr;

		free(tmp);

		tmp = nullptr;
	}

	return ;
}


void Btree::bstRemove(const Square& square)
{
	remove_helper(&m_root, square);
}
