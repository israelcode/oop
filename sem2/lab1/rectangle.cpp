#include "rectangle.h"

Rectangle::Rectangle()
{
	m_sideA = 0.0;
	m_sideB = 0.0;
}

Rectangle::Rectangle(std::istream& is)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side A: ";
	is >> m_sideA;
	if (!is){
	m_sideA=0;
	is.clear();
	is.ignore();}
	std::cout << "Enter side B: ";
	is >> m_sideB;
}

Rectangle::Rectangle(size_t i,size_t j) : m_sideA(i), m_sideB(j)
{
    std::cout << "Rectangle passed to function. Sides: " << m_sideA << ", " << m_sideB << std::endl;
}



void Rectangle::print() const
{
	std::cout << "================" << std::endl;
	std::cout << "Figure type: rectangle" << std::endl;
	std::cout << "Side A size: " << m_sideA << std::endl;
	std::cout << "Side B size: " << m_sideB << std::endl;
}

double Rectangle::area() const
{
	return m_sideA * m_sideB;
}
