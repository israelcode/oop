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
		result = head->getItem();
		head = head->GetNext();
	}
	m_size--;
	return result;
}

template <class T>
void Stack<T>::erase(const std::shared_ptr<Stack<T>>& stack1, int i, int size, Stack<T> stack2)
{

	int j=0;
	int q=0;
	int key=0;
	int firstd=0;

	if(stack1->size()==1){
		key=1;
		}
	while(true){

		if(j==(i)){ 
			stack1->Pop();
			firstd=1;
			if(firstd==1){
			
				while((stack1->size()!=0)){
					std::shared_ptr<StackItem<T>> other=stack1->head;
					stack2.Push(other->getItem());
					stack1->Pop();
					j++;
					key=22;
						
				}	
			}
				j++;
				if(key==1){
					key=22;	
				} 
		}

		else if(j<(i)){  
			std::shared_ptr<StackItem<T>> other=stack1->head;
			stack2.Push(other->getItem());
			stack1->Pop();
			j++;
		
		q=stack2.size();
		
		if(firstd==1){key=22;}
		if(key==22){

			if((stack1->size()==0)&&(stack2.size()!=0)){
					while(q>0){
						std::shared_ptr<StackItem<T>> other=stack2.head;
						stack1->Push(other->getItem());
						stack2.Pop();
						q--;
					}
				break;
			}
		else{break;}	
		}
	}

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
}



			}
		else{break;}	
		}
	}

}
