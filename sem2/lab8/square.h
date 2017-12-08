#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "figure.h"

class Square : public Figure
{
public:
	Square();
	Square(std::istream& is);
	Square(size_t i);

	void print() const override;
	double area() const override;
	

	Square& operator = (const Square& other);
	bool operator == (const Square& other) const;
	bool operator < (const Square& rhs) const;
	bool operator > (const Square& rhs) const;

	void* operator new (unsigned int size);
	void operator delete (void* p);


	friend std::ostream& operator << (std::ostream& os, const Square& square);
	friend std::istream& operator >> (std::istream& is, Square& square);
private:
	double m_side;
};

#endif
