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
}

Square::Square(size_t i) : m_side(i) //!!
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

Square& Square::operator = (const Square& other)
{
	if (&other == this)
		return *this;

	m_side = other.m_side;

	return *this;
}

void* Square::operator new (unsigned int size)
{
	return Figure::allocator.allocate();
}

void Square::operator delete (void* p)
{
	Figure::allocator.deallocate(p);
}


bool Square::operator < (const Square& rhs) const
{
  return (this->area() < rhs.area());
}

bool Square::operator > (const Square& rhs) const
{
  return (this->area() > rhs.area());
}

bool Square::operator == (const Square& other) const
{
	return m_side == other.m_side;
}

bool Figure::operator > (const Figure& rhs) const
	{
	  return (this->area() > rhs.area());
	}
bool Figure::operator < (const Figure& rhs) const
	{
	  return (this->area() < rhs.area());
	}

bool Figure::operator == (const Figure& rhs) const
	{
	  return area() == rhs.area();
	}
std::ostream& operator << (std::ostream& os, const Square& square)
{
	os << "================" << std::endl;
	os << "Figure type: square" << std::endl;
	os << "Side size: " << square.m_side << std::endl;

	return os;
}

std::istream& operator >> (std::istream& is, Square& square)
{
	std::cout << "================" << std::endl;
	std::cout << "Enter side: ";
	is >> square.m_side;

	return is;
}

std::ostream& operator << (std::ostream& os, const Figure& figure)
{
	figure.print();	
	
	return os;
}

