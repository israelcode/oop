#include "rectangle.h"

Rectangle::Rectangle()
{
	m_sideA = 0.0;
	m_sideB = 0.0;
}

Rectangle::Rectangle(std::istream& is)
{
	is >> *this;
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

Rectangle& Rectangle::operator = (const Rectangle& other)
{
	if (&other == this)
		return *this;

	m_sideA = other.m_sideA;
	m_sideB = other.m_sideB;

	return *this;
}

bool Rectangle::operator == (const Rectangle& other) const
{
	return m_sideA == other.m_sideA && m_sideB == other.m_sideB;
}


bool Rectangle::operator < (const Rectangle& rhs) const
{
  return (this->area() < rhs.area());
}


bool Rectangle::operator > (const Rectangle& rhs) const
{
  return (this->area() > rhs.area());
}

std::ostream& operator << (std::ostream& os, const Rectangle& rectangle)
{
	os << "================" << std::endl;
	os << "Figure type: rectangle" << std::endl;
	os << "Side A size: " << rectangle.m_sideA << std::endl;
	os << "Side B size: " << rectangle.m_sideB << std::endl;

	return os;
}

std::istream& operator >> (std::istream& is, Rectangle& rectangle)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side A: ";
	is >> rectangle.m_sideA;
	std::cout << "Enter side B: ";
	is >> rectangle.m_sideB;

	return is;
}
