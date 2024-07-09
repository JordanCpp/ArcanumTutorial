#include <Decompressor/Decompressor.hpp>
#include <zlib.h>

bool Decompressor::Uncompress(uint8_t* dest, size_t destSize, uint8_t* src, size_t srcSize)
{
	int z_err = uncompress(dest, (uLongf*)&destSize, src, (uLong)srcSize);

	return z_err == 0;
}