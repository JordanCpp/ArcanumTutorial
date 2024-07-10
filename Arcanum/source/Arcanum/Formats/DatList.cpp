#include <Arcanum/Formats/DatList.hpp>

using namespace Aracnum;

DatItem* DatList::GetItem(const std::string& file)
{
	std::map<std::string, DatItem>::iterator i = m_List.find(file);

	if (i != m_List.end())
	{
		return &i->second;
	}

	return NULL;
}
