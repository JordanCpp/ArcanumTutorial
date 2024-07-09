#ifndef Decompressor_hpp
#define Decompressor_hpp

#include <stddef.h>

class Decompressor
{
public:
	bool Uncompress(unsigned char* dest, size_t destSize, unsigned char* src, size_t srcSize);
private:
};

#endif
