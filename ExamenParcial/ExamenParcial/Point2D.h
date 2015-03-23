#ifndef __Point2D_H__
#define __Point2D_H__

#include <math.h>

class Point2D
{
public:

	float x, y;


	Point2D& operator+ (const Point2D &p) const;

	Point2D& operator- (const Point2D &p) const;

	const Point2D& operator+= (const Point2D &p);

	const Point2D& operator-=(const Point2D &p);

	bool operator==(const Point2D &p) const;

	bool operator!=(const Point2D &p) const;

	bool isZero() const;

	void setZero();

	float distanceTo(const Point2D &p) const;
};





#endif