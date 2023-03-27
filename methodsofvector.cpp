#include "vector.h"
using namespace std;
using namespace vector;
Vector::Vector(double x, double y, double z)
	:x(x),y(y),z(z)
{
}

/*
Vector::Vector(Point& firstPoint, Point& secondPoint)
{
	x = secondPoint.GetX() - firstPoint.GetX();
	y = secondPoint.GetY() - firstPoint.GetY();
	z = secondPoint.GetZ() - firstPoint.GetZ();
}
*/

Vector::~Vector() 
{
}
void Vector::Print() const
{
	cout << "(" << x << ", " << y << ", " << z << ")" << endl;
}
double Vector::GetX() const
{
	return x;
}
double Vector::GetY() const
{
	return y;
}
double Vector::GetZ() const
{
	return z;
}
double Vector::GetLenght() const
{
	return sqrt(x * x + y * y + z * z);
}

Vector Vector::GetOrt()
{
	const double lenght = this->GetLenght();
	return Vector(x / lenght, y / lenght, z / lenght);
}
Vector Vector::MultipVectorOnScalar(double scalar)
{
	return Vector(x * scalar, y * scalar, z * scalar);
}

Vector vector::SumVectors(const Vector &vector1, const Vector &vector2)
{
	return Vector(vector1.GetX() + vector2.GetX(), vector1.GetY() + vector2.GetY(), vector1.GetZ() + vector2.GetZ());
}
Vector vector::SubVectors(const Vector& vector1, const Vector& vector2)
{
	return Vector(vector1.GetX() - vector2.GetX(), vector1.GetY() - vector2.GetY(), vector1.GetZ() - vector2.GetZ());
}
double vector::ScalarMultipVectors(const Vector& vector1, const Vector& vector2)
{
	return vector1.GetX() * vector2.GetX() + vector1.GetY() * vector2.GetY() + vector1.GetZ() * vector2.GetZ();
}
Vector vector::VectorMultipVectors(const Vector& vector1, const Vector& vector2)
{
	const double valueX = vector1.GetY() * vector2.GetZ() - vector2.GetY() * vector1.GetZ();
	const double valueY = -(vector1.GetX() * vector2.GetZ()) + vector2.GetX() * vector1.GetZ();
	const double valueZ = vector1.GetX() * vector2.GetY() - vector2.GetX() * vector1.GetY();
	return Vector(valueX, valueY, valueZ);
}
double vector::MixedMultipVectors(const Vector& vector1, const Vector& vector2, const Vector& vector3)
{
	const double value1 = vector1.GetX() * (vector2.GetY() * vector3.GetZ() - vector3.GetY() * vector2.GetZ());
	const double value2 = vector1.GetY() * (-(vector2.GetX() * vector3.GetZ() - vector3.GetX() * vector2.GetZ()));
	const double value3 = vector1.GetZ() * (vector2.GetX() * vector3.GetY() - vector3.GetX() * vector2.GetY());
	return value1 + value2 + value3;
}
Vector vector::FindingNormalVectors(const Vector &vector1, const Vector &vector2)
{
	return VectorMultipVectors(vector1, vector2);
}
Vector vector::ReflectedVectorFromThePlane(const Vector& vector, const Plane& normal)
{
	if (normal.GetX() != 0)
		return Vector(vector.GetX() * (-1), vector.GetY(), vector.GetZ());
	else if (normal.GetY() != 0)
		return Vector(vector.GetX(), vector.GetY() * (-1), vector.GetZ());
	else
		return Vector(vector.GetX(), vector.GetY(), vector.GetZ() * (-1));
}

Vector vector::ReflectedVectorFromTheLine(const Vector& vector, const Plane& normal1, const Plane& normal2)
{
	if (normal1.GetX() != 0)
		if (normal2.GetY() != 0)
			Vector((-1) * (vector.GetX() / abs(vector.GetX())) * abs(vector.GetY()), (-1) * (vector.GetY() / abs(vector.GetY())) * abs(vector.GetX()), vector.GetZ());
		else
			return Vector((-1) * (vector.GetX() / abs(vector.GetX())) * abs(vector.GetZ()), vector.GetY(), (-1) * (vector.GetZ() / abs(vector.GetZ())) * abs(vector.GetX()));
	else if (normal1.GetY() != 0)
		if (normal2.GetX() != 0)
			return Vector((-1) * (vector.GetX() / abs(vector.GetX())) * abs(vector.GetY()), (-1) * (vector.GetY() / abs(vector.GetY())) * abs(vector.GetX()), vector.GetZ());
		else
			return Vector(vector.GetX(), (-1) * (vector.GetY() / abs(vector.GetY())) * abs(vector.GetZ()), (-1) * (vector.GetZ() / abs(vector.GetZ())) * abs(vector.GetY()));
	else
		if (normal2.GetX() != 0)
			return Vector((-1) * (vector.GetX() / abs(vector.GetX())) * abs(vector.GetZ()), vector.GetY(), (-1) * (vector.GetZ() / abs(vector.GetZ())) * abs(vector.GetX()));
		else
			return Vector(vector.GetX(), (-1) * (vector.GetY() / abs(vector.GetY())) * abs(vector.GetZ()), (-1) * (vector.GetZ() / abs(vector.GetZ())) * abs(vector.GetY()));
}

Vector vector::ReflectedVectorFromThePoint(const Vector& vector)
{
	return Vector(-(vector.GetX() / abs(vector.GetX())) * abs(vector.GetY()), -(vector.GetY() / abs(vector.GetY())) * abs(vector.GetX()), -(vector.GetZ()));
}

bool vector::ThePointBelongsToThePlane(const Plane& plane, const Point& point)
{
	return (plane.GetX() * point.GetX() + plane.GetY() * point.GetY() + plane.GetZ() * point.GetZ() + plane.GetFreeMember() == 0);
}

Point vector::IntersectionPointOfTheVectorAndThePlane(const Plane &plane, const Vector &vector, const Point &point)
{
	double coefficientOfT = vector.GetX() * plane.GetX() + vector.GetY() * plane.GetY() + vector.GetZ() * plane.GetZ();
	double freeMember = point.GetX() * plane.GetX() + point.GetY() * plane.GetY() + point.GetZ() * plane.GetZ() + plane.GetFreeMember();
	double t = -(freeMember) / coefficientOfT;
	return Point(vector.GetX() * t + point.GetX(), vector.GetY() * t + point.GetY(), vector.GetZ() * t + point.GetZ());
}

Vector vector::ConstructionOfVectorByTwoPoints(Point& firstPoint, Point& secondPoint)
{
	return Vector(secondPoint.GetX() - firstPoint.GetX(), secondPoint.GetY() - firstPoint.GetY(), secondPoint.GetZ() - firstPoint.GetZ());
}