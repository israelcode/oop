#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "figure.h"

class Rectangle : public Figure
{
public:
	Rectangle();                 
	Rectangle(std::istream& is); 
	Rectangle(size_t i, size_t j);//!!

	void print() const override;
	double area() const override;

private:
	double m_sideA;
	double m_sideB;
};

#endif
