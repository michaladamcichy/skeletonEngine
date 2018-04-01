#pragma once
class MyPoint
{
public:
	double x;
	double y;
	double z = 0;
	MyPoint();
	MyPoint(double inX, double inY, double inZ);
	void define(double inX, double inY, double inZ);
	void trans(double inX, double inY, double inZ);
	MyPoint operator + (const MyPoint& point);
	MyPoint operator - (const MyPoint& point);
	MyPoint operator * (const double& multiplier);
	MyPoint operator / (const double& divider);
	MyPoint operator += (const MyPoint& point);
	MyPoint operator -= (const MyPoint& point);
	MyPoint operator *= (const double& multiplier);
	MyPoint operator /= (const double& divider);
	void print();
};

MyPoint::MyPoint()
{

}
MyPoint::MyPoint(double inX, double inY, double inZ = 0)
{
	x = inX;
	y = inY;
	z = inZ;
}
void MyPoint::define(double inX, double inY, double inZ = 0)
{
	x = inX;
	y = inY;
	z = inZ;
}
void MyPoint::trans(double inX, double inY, double inZ = 0)
{
	x += inX;
	y += inY;
	z += inZ;
}
MyPoint MyPoint::operator + (const MyPoint& point)
{
	return { this->x + point.x, this->y + point.y, this->z + point.z };
}
MyPoint MyPoint::operator - (const MyPoint& point)
{
	return { this->x - point.x, this->y - point.y, this->z - point.z };
}
MyPoint MyPoint::operator * (const double& multiplier)
{
	return { this->x * multiplier, this->y * multiplier, this->z * multiplier };
}
MyPoint MyPoint::operator / (const double& divider)
{
	return { this->x / divider, this->y / divider, this->z / divider };
}
MyPoint MyPoint::operator += (const MyPoint& point)
{
	return *this + point;
}
MyPoint MyPoint::operator -= (const MyPoint& point)
{
	return *this - point;
}
MyPoint MyPoint::operator *= (const double& multiplier)
{
	return *this * multiplier;
}
MyPoint MyPoint::operator /= (const double& divider)
{
	return *this / divider;
}
void MyPoint::print()
{
		if (z == 0)
			printf("(%lf,%lf)", x, y);
		else
			printf("(%lf,%lf,%lf)", x, y, z);
}