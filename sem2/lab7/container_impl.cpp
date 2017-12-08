template <class T>
void Container<T>::add(const std::shared_ptr<T>& item)
{
auto lastContIt = m_container.begin();
	if (lastContIt == m_container.end()){
	m_container.bstInsert(std::make_shared<Stack<T>>());
	}

lastContIt = m_container.begin();	

while (lastContIt.getItem()->GetNext() != nullptr){
	++lastContIt;
	}
if ((*lastContIt)->size() == 5)
	{
		m_container.bstInsert(std::make_shared<Stack<T>>());
		++lastContIt;	
	}
(*lastContIt)->Push(item);

}

template <class T>
void Container<T>::erase(const Criteria<T>& criteria)
{
int size=0;
for (auto subCont : m_container)
	{
		while (true)
		{
			bool isRemoved = false;

			for (unsigned int i = 0; i < subCont->size(); ++i)
			{
				auto elemIt = subCont->get(i);
				size=subCont->size();

				if (criteria.check(*elemIt))
				{		
									
					subCont->erase(subCont, i,size, stack2);
					isRemoved = true;				
					break;
				}
			}

			if (!isRemoved)
				break;
		}
	}	


template <class K>
std::ostream& operator << (std::ostream& os, const Container<K>& container)
{
	if (container.m_container.size() == 0)
	{
		os << "================" << std::endl;
		os << "Container is empty" << std::endl;
	}
	else
	{
		unsigned int containerCnt1 = 1;

		for (auto subCont : container.m_container)
		{
			unsigned int containerCnt2 = 1;

			os << "================" << std::endl;
			os << "Container #" << (containerCnt1++) << ":" << std::endl;
			
			for (auto subItem : *subCont)
			{
				os << "================" << std::endl;
				os << "Item #" << (containerCnt2++) << ":" << std::endl;
				
				subItem->print();

				os << "Area: " << subItem->area() << std::endl;
			}
		}
	}

	return os;
}

