#ifndef __Circle_H__
#define __Circle_H__

#include "Point2D.h"

class Circle
{
public:

	Point2D center;
	float radius;

	Circle()
	{
		center.x = 0;
		center.y = 0;
		radius = 1;
	}

	Circle(const Point2D& c, const float& r)
	{
		center.x = c.x;
		center.y = c.y;
		radius = r;
	}

	float Area() const
	{
		float pi = 3.141592;
		return pi * radius * radius;
	}

	bool Intersection(const Circle& c) const
	{
		if (center.distanceTo(c.center) >= radius + c.radius)
			return true;

		else
			return false;
	}

};
#endif