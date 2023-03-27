#include "vector.h"
using namespace std;
using namespace vector;

Point::Point(double x, double y, double z)
	:x(x), y(y), z(z)
{
}

Point::Point()
{
}

Point::~Point()
{
}

double Point::GetX() const
{
	return x;
}

double Point::GetY() const
{
	return y;
}

double Point::GetZ() const
{
	return z;
}

void Point::Print() const
{
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}

Point vector::FindingPointBetweenTwoOthersThroughRatio(Point& firstPoint, Point& secondPoint, double ratio)
{
	double X = firstPoint.GetX() + (secondPoint.GetX() - firstPoint.GetX()) * ratio;
	double Y = firstPoint.GetY() + (secondPoint.GetY() - firstPoint.GetY()) * ratio;
	double Z = firstPoint.GetZ() + (secondPoint.GetZ() - firstPoint.GetZ()) * ratio;
	return Point (X, Y, Z);
}

Plane::Plane()
{
}

Plane::Plane(double x, double y, double z, double freeMember)
	:x(x), y(y), z(z), freeMember(freeMember)
{
}

Plane::~Plane()
{

}

double Plane::GetX() const
{
	return x;
}

double Plane::GetY() const
{
	return y;
}

double Plane::GetZ() const
{
	return z;
}

double Plane::GetFreeMember() const
{
	return freeMember;
}

void Plane::Print() const
{
	cout << x << "x + " << y << "y + " << z << "z + " << freeMember << " = 0" << endl;
}