#ifndef Decompressor_hpp
#define Decompressor_hpp

#include <cstdint>

class Decompressor
{
public:
	bool Uncompress(uint8_t* dest, size_t destSize, uint8_t* src, size_t srcSize);
private:
};

#endif     