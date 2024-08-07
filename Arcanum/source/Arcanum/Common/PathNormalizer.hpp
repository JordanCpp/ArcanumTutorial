#ifndef Aracnum_Common_PathNormalizer_hpp
#define Aracnum_Common_PathNormalizer_hpp

#include <Pollux/Containers/String.hpp>

namespace Arcanum
{
	class PathNormalizer
	{
	public:
		void Normalize(char* path);
		void Normalize(Pollux::String& path);
	private:
	};
}

#endif
