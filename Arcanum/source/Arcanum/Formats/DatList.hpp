#ifndef Aracnum_Formats_DatList_hpp
#define Aracnum_Formats_DatList_hpp

#include <string>
#include <map>
#include <Arcanum/Formats/DatItem.hpp>

namespace Aracnum
{
    class DatList
    {
    public:
        DatItem* GetItem(const std::string& file);
        std::map<std::string, DatItem> m_List;
    };
}

#endif
