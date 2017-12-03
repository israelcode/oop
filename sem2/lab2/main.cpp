#include "btree.h"

int main()
{
	unsigned int action;
	Btree b;

	while (true)
	{
		std::cout << "================" << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "1) Add figure" << std::endl;
		std::cout << "2) Delete figure" << std::endl;
		std::cout << "3) Print" << std::endl;
		std::cout << "0) Quit" << std::endl;
		std::cin >> action;

		if (action == 0)
			break;

		if (action > 3)
		{
			std::cout << "Error: invalid action" << std::endl;

			continue;
		}

		switch (action)
		{
			case 1:
			{			
				b.bstInsert(std::cin);

				break;
			}

			case 2:
			{
				Square square(std::cin);
				b.bstRemove(square);

				break;
			}

			case 3:
			{
				std::cout << b;

				break;
			}
		}
	}
	
	return 0;
}
