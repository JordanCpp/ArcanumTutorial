#include <Arcanum/Graphics/Isometric.hpp>

using namespace Arcanum;

const Point& Isometric::CartesianToIsometric(const Point& pt)
{
	int x = pt.x - pt.y;
	int y = (pt.x + pt.y) / 2;

	_Result = Point(x, y);

	return _Result;
}

const Point& Isometric::IsometricToCartesian(const Point& pt)
{
	int x = (2 * pt.y + pt.x) / 2;
	int y = (2 * pt.y - pt.x) / 2;

	_Result = Point(x, y);

	return _Result;
}
