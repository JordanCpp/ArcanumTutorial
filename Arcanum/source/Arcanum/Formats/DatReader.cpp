#include <Arcanum/Formats/DatReader.hpp>
#include <string.h>

using namespace Aracnum;

bool DatReader::Reset(const std::string& file, DatList& archiveList)
{
	if (_File.is_open())
		_File.close();

	_File.open(file.c_str(), std::ios::binary);

	if (_File.is_open())
	{
		int treesubs   = 0;	
		int filestotal = 0;

		_File.seekg(-0x1Cl, std::ios::end);
		_File.seekg(16, std::ios::cur);
		_File.seekg(4, std::ios::cur);
		_File.seekg(4, std::ios::cur);
		_File.read((char*)&treesubs, 0x04);
		_File.seekg(-treesubs, std::ios::end);
		_File.read((char*)&filestotal, 0x04);

		for (int i = 1; i <= filestotal; i++)
		{
			DatItem item;

			_File.read((char*)&item.NameSize, 0x04);
			_File.read((char*)&item.Name, item.NameSize);

			_PathNormalizer.Normalize(item.Name);

			_File.read((char*)&item.Unknown1, 0x04);
			_File.read((char*)&item.Type, 0x04);
			_File.read((char*)&item.RealSize, 0x04);
			_File.read((char*)&item.PackedSize, 0x04);
			_File.read((char*)&item.Offset, 0x04);

			strcpy(item.Archive, file.c_str());

			std::map<std::string, DatItem>::iterator j = archiveList.m_List.find(item.Name);

			if (j == archiveList.m_List.end())
			{
				_Name = item.Name;
				archiveList.m_List.insert(std::make_pair(_Name, item));
			}
			else
			{
				strcpy(j->second.Archive, file.c_str());
			}
		}

		_File.close();

		return true;
	}

	return false;
}
