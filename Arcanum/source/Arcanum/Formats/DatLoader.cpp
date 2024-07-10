#include <Arcanum/Formats/DatLoader.hpp>
#include <stdexcept>

using namespace Aracnum;

DatLoader::DatLoader(DatList* archiveList) :
	_ArchiveList(archiveList)
{
	_Result.reserve(DatLoader::Bytes);
	_Buffer.reserve(DatLoader::Bytes);
}

std::vector<uint8_t>& DatLoader::GetData(const std::string& path)
{
	_Result.clear();
	_Buffer.clear();

	DatItem* p = _ArchiveList->GetItem(path);

	if (p != NULL)
	{
		_File.open(p->Archive, std::ios::binary);

		if (_File.is_open())
		{
			if (p->Type == DatItem::Uncompressed)
			{
				_File.seekg(p->Offset, std::ios::beg);

				_Result.resize(p->RealSize);

				_File.read((char*)&_Result[0], p->RealSize);
			}
			else if (p->Type == DatItem::Compressed)
			{
				_File.seekg(p->Offset, std::ios::beg);

				_Result.resize(p->RealSize);
				_Buffer.resize(p->PackedSize);

				_File.read((char*)&_Buffer[0], p->PackedSize);

				if (!_Unpacker.Uncompress((unsigned char*)&_Result[0], p->RealSize, (unsigned char*)&_Buffer[0], p->PackedSize))
				{
					throw std::runtime_error("Can't uncompress file: " + path);
				}
			}

			_File.close();
		}
	}

	return _Result;
}
