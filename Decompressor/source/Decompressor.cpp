#include <Decompressor/Decompressor.hpp>
#include <zlib.h>

bool Decompressor::Uncompress(unsigned char* dest, size_t destSize, unsigned char* src, size_t srcSize)
{
	int z_err = uncompress(dest, (uLongf*)&destSize, src, (uLong)srcSize);

	return z_err == 0;
}
