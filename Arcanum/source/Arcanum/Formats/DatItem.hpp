#ifndef Aracnum_Formats_DatItem_hpp
#define Aracnum_Formats_DatItem_hpp

namespace Aracnum
{
    class DatItem
    {
    public:
        enum
        {
            Uncompressed = 0x01,
            Compressed   = 0x02,
            MaxPath      = 128,
            MaxName      = 64
        };

        DatItem();

        int  NameSize;
        char Name[MaxPath];
        int  Unknown1;
        int  Type;
        int  RealSize;
        int  PackedSize;
        int  Offset;
        char Archive[MaxName];
    };
}

#endif
