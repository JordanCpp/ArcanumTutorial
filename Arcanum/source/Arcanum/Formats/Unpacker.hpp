#ifndef Arcanum_Formats_Unpacker_hpp
#define Arcanum_Formats_Unpacker_hpp

#include <stddef.h>

namespace Aracnum
{
	class Unpacker
	{
	public:
		bool Uncompress(unsigned char* dest, size_t destSize, unsigned char* src, size_t srcSize);
	private:
	};
}

#endif
