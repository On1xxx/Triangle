#include "triangle.hpp"

/*****************************************************************************/

Triangle::Triangle(double _a1, double _a2, double _b1, double _b2, double _c1, double _c2)
	:a(_a1,_a2), b(_b1,_b2), c(_c1, _c2)
{}

Triangle::Triangle(Point _a, Point _b, Point _c)
	:a(_a), b(_b), c(_c)
{}

bool Triangle::operator == (Triangle T) const
{
	return (a == T.a) && (b == T.b) && (c == T.c);
}

bool Triangle::operator != (Triangle T) const
{
	return !(*this == T);
}

bool Triangle::isRectangular() const
{
	return ( getArea() == ( 0.5 * getSide12Length() * getSide23Length()) )
		|| (getArea() == (0.5 * getSide23Length() * getSide13Length()) )
		|| (getArea() == (0.5 * getSide12Length() * getSide13Length()) );
}
bool Triangle::isIsosceles() const
{
	return (getSide12Length() == getSide23Length() || getSide23Length() == getSide13Length() || getSide12Length() == getSide13Length());
}

bool Triangle::isEquilateral() const
{
	return equalDoubles(getSide12Length(), getSide23Length()) && equalDoubles(getSide12Length(), getSide13Length());
}


/*****************************************************************************/