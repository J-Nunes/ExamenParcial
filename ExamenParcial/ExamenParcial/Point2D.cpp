#include <math.h>
#include "Point2D.h"

Point2D& Point2D::operator+ (const Point2D &p) const
{
	Point2D tmp;

	tmp.x = x + p.x;
	tmp.y = y + p.y;

	return(tmp);
}

Point2D& Point2D::operator- (const Point2D &p) const
{
	Point2D tmp;

	tmp.x = x - p.x;
	tmp.y = y - p.y;

	return(tmp);
}

const Point2D& Point2D::operator+= (const Point2D &p)
{
	x += p.x;
	y += p.y;

	return *this;
}

const Point2D& Point2D::operator-=(const Point2D &p)
{
	x -= p.x;
	y -= p.y;

	return *this;
}

bool Point2D::operator==(const Point2D &p) const
{
	return (x == p.x && y == p.y);
}

bool Point2D::operator!=(const Point2D &p) const
{
	return (x != p.x || y != p.y);
}

bool Point2D::isZero() const
{
	return x == 0.0f && y == 0.0f;
}

void Point2D::setZero()
{
	x = y = 0.0f;
}

float Point2D::distanceTo(const Point2D &p) const
{
	return sqrt(pow(p.x - x, 2) + pow(p.y - y, 2));
}