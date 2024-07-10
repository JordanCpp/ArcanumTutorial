#ifndef Aracnum_Formats_DatLoader_hpp
#define Aracnum_Formats_DatLoader_hpp

#include <fstream>
#include <vector>
#include <Arcanum/Types.hpp>
#include <Arcanum/Formats/DatList.hpp>
#include <Arcanum/Formats/Unpacker.hpp>

namespace Aracnum
{
	class DatLoader
	{
	public:
		enum
		{
			Bytes = 1024 * 1024
		};
		DatLoader(DatList* archiveList);
		std::vector<uint8_t>& GetData(const std::string& path);
	private:
		Unpacker              _Unpacker;
		std::ifstream         _File;
		std::vector<uint8_t>  _Result;
		std::vector<uint8_t>  _Buffer;
		DatList*              _ArchiveList;
	};
}

#endif    
