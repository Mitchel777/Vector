#pragma once
#include <iostream>
#include <string>
namespace vector 
{
	struct Vector
	{
	public:
		Vector(double x, double y, double z);
		/*
		Vector(Point& firstPoint, Point& secondPoint);
		*/
		~Vector();
		void Print() const;
		double GetX() const;
		double GetY() const;
		double GetZ() const;
		double GetLenght() const;
		Vector GetOrt();
		Vector MultipVectorOnScalar(double scalar);
	private:
		double x;
		double y;
		double z;
	};
	struct Point
	{
	public:
		Point(double x, double y, double z);
		Point();
		~Point();
		double GetX() const;
		double GetY() const;
		double GetZ() const;
		void Print() const;

	private:
		double x;
		double y;
		double z;
	};
	struct Plane
	{
	public:
		Plane();
		Plane(double x, double y, double z, double freeMember);
		~Plane();
		double GetX() const;
		double GetY() const;
		double GetZ() const;
		double GetFreeMember() const;
		void Print() const;
	private:
		double x;
		double y;
		double z;
		double freeMember;
	};
	Vector SumVectors(const Vector& vector1, const Vector& vector2);
	Vector SubVectors(const Vector& vector1, const Vector& vector2);
	double ScalarMultipVectors(const Vector& vector1, const Vector& vector2);
	Vector VectorMultipVectors(const Vector& vector1, const Vector& vector2);
	double MixedMultipVectors(const Vector& vector1, const Vector& vector2, const Vector& vector3);
	Vector FindingNormalVectors(const Vector& vector1, const Vector& vector2);
	Vector ReflectedVectorFromThePlane(const Vector& vector, const Plane& normal);
	Vector ReflectedVectorFromTheLine(const Vector& vector, const Plane& normal1, const Plane& normal2);
	Vector ReflectedVectorFromThePoint(const Vector& vector);
	bool ThePointBelongsToThePlane(const Plane& plane, const Point& point);
	Point IntersectionPointOfTheVectorAndThePlane(const Plane& plane, const Vector& vector, const Point& point);
	Vector ConstructionOfVectorByTwoPoints(Point& firstPoint, Point& secondPoint);
	Point FindingPointBetweenTwoOthersThroughRatio(Point& firstPoint, Point& secondPoint, double ratio);
}