#include <Arcanum/Formats/Unpacker.hpp>
#include <zlib.h>

namespace Aracnum
{
	bool Unpacker::Uncompress(unsigned char* dest, size_t destSize, unsigned char* src, size_t srcSize)
	{
		return (uncompress(dest, (uLongf*)&destSize, src, (uLong)srcSize) == 0);
	}
}
