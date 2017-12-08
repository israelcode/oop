#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <cstdlib>
#include "stack.h"


class Allocator
{
public:
	Allocator(unsigned int blockSize, unsigned int count);
	~Allocator();

	void* allocate();
	void deallocate(void* p);
	bool hasFreeBlocks() const;

private:
size_t _size;
size_t _count;
char *_used_blocks;
void **_free_blocks;
size_t _free_count;

};

#endif

