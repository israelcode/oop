#include "square.h"


Square::Square()
{
	m_side = 0.0;
}

Square::Square(std::istream& is)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side: ";
	is >> m_side;
	if (!is){
	m_side=0;
	is.clear();
	is.ignore();
}
}

Square::Square(size_t i) : m_side(i)
{
    std::cout << "Square passed to function. Side: " << m_side << std::endl;
}

void Square::print() const
{
	std::cout << "================" << std::endl;
	std::cout << "Figure type: square" << std::endl;
	std::cout << "Side size: " << m_side << std::endl;
}

double Square::area() const
{
	return m_side * m_side;
}
