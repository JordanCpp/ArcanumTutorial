#include <Arcanum/Formats/DatItem.hpp>
#include <string.h>

using namespace Aracnum;

DatItem::DatItem() :
	NameSize(0),
	Unknown1(0),
	Type(0),
	RealSize(0),
	PackedSize(0),
	Offset(0)
{
	memset(Name, 0, DatItem::MaxPath);
	memset(Archive, 0, DatItem::MaxName);
}
