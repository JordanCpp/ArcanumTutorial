#ifndef Aracnum_Formats_DatReader_hpp
#define Aracnum_Formats_DatReader_hpp

#include <Arcanum/Formats/DatList.hpp>
#include <Arcanum/Common/PathNormalizer.hpp>
#include <fstream>

namespace Aracnum
{
    class DatReader
    {
    public:
        bool Reset(const std::string& file, DatList& archiveList);
    private:
        PathNormalizer _PathNormalizer;
        std::string    _Name;
        std::ifstream  _File;
    };
}

#endif 
