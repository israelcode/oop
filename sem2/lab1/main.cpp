#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

void testFigure(Figure* figure);

int main()
{
char action;
	while (action)
	{
		std::cout << "================" << std::endl;
		std::cout << "Menu:" << std::endl;
		std::cout << "1)Square" << std::endl;
		std::cout << "2)Rectangle" << std::endl;
		std::cout << "3)Trapezoid" << std::endl;
		std::cout << "0) Quit" << std::endl;
		std::cin >> action;

		if (action == '0'){break;}
		
		if (action == '1'){
			testFigure(new Square(std::cin));
			break;
		}
		if (action == '2'){
		testFigure(new Rectangle(std::cin));
		break;
		}
		if (action == '3'){
		testFigure(new Trapezoid(std::cin));
		break;
		}

	}
}
void testFigure(Figure* figure){
	figure->print();

	std::cout << "Area: " << figure->area() << std::endl;

	delete figure;
}
