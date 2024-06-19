#ifndef Game_Painters_Isometric_hpp
#define Game_Painters_Isometric_hpp

#include <Arcanum/Graphics/Point.hpp>

namespace Arcanum
{
    class Isometric
    {
    public:
        const Point& CartesianToIsometric(const Point& pt);
        const Point& IsometricToCartesian(const Point& pt);
    private:
        Point _Result;
    };
}

#endif
