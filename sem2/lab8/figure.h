#ifndef FIGURE_H
#define FIGURE_H

#include "allocator.h"

class Figure
{
public:
	virtual ~Figure() {} //деструктор класса
	virtual void print() const = 0;
	virtual double area() const = 0;
	bool operator > (const Figure& rhs) const;
	bool operator < (const Figure& rhs) const;
	bool operator == (const Figure& rhs) const;
	friend std::ostream& operator << (std::ostream& os, const Figure& figure);
	static Allocator allocator;
};

#endif
