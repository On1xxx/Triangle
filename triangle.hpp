#ifndef _TRIANGLE_HPP_
#define _TRIANGLE_HPP_

/*****************************************************************************/

#include "point.hpp"

/*****************************************************************************/


class Triangle
{

	Point a, b, c;

public:
	Triangle(double _a1, double _a2, double _b1, double _b2, double _c1, double _c2);
	Triangle(Point _a, Point _b, Point _c);
	
	double getSide12Length() const;
	double getSide23Length() const;
	double getSide13Length() const;
	double getPerimeter() const;
	double getArea() const;
	double getAngle1() const;
	double getAngle2() const;
	double getAngle3() const;

	bool isRectangular() const;
	bool isIsosceles() const;
	bool isEquilateral() const;

	Point getPoint1() const;
	Point getPoint2() const;
	Point getPoint3() const;

	bool operator == (Triangle T) const;
	bool operator != (Triangle T) const;

};


inline
Point Triangle::getPoint1() const
{
	return a;
}

inline
Point Triangle::getPoint2() const
{
	return b;
}

inline
Point Triangle::getPoint3() const
{
	return c;
}

inline
double Triangle::getSide12Length() const
{
	return a.distanceTo(b);
}

inline
double Triangle::getSide23Length() const
{
	return b.distanceTo(c);
}

inline
double Triangle::getSide13Length() const
{
	return a.distanceTo(c);
}

inline
double Triangle::getPerimeter() const
{
	return  getSide12Length() + getSide23Length() + getSide13Length();
}

inline
double Triangle::getArea() const
{
	double p = getPerimeter() / 2;
	return sqrt(p*(p - getSide12Length())*(p - getSide23Length())*(p - getSide13Length()));
}

inline
double Triangle::getAngle1() const
{
	return acos((getSide13Length()*getSide13Length() - getSide12Length() *getSide12Length() + getSide23Length()*getSide23Length()) / (2.0 * getSide13Length() * getSide23Length()));
}

inline
double Triangle::getAngle2() const
{
	return acos((getSide12Length()*getSide12Length() - getSide13Length() *getSide13Length() + getSide23Length()*getSide23Length()) / (2 * getSide12Length() *getSide23Length()));
}

inline
double Triangle::getAngle3() const
{
	return acos((getSide12Length()*getSide12Length() - getSide23Length() *getSide23Length() + getSide13Length()*getSide13Length()) / (2 * getSide12Length() *getSide13Length()));
}
/*****************************************************************************/

#endif //  _TRIANGLE_HPP_