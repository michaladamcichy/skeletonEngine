#pragma once
class MyPlane
{
/*
A*x + B*y + C*z - D = 0; 
*/
private:
	double A, B, C;
public:
	MyPlane();
	MyPlane(MyPoint A, MyPoint B, MyPoint C);
	void define(MyPoint A, MyPoint B, MyPoint C);
	bool crossedByLine(MyLine line, MyPoint& crossing);
	void printInfo();
	~MyPlane();
};

MyPlane::MyPlane(){}
MyPlane::MyPlane(MyPoint P1, MyPoint P2, MyPoint P3)
{
	double a[] = {P1.x, P2.x, P3.x};
	double b[] = {P1.y, P2.y, P3.y};
	double c[] = {1, 1, 1};
	double d[] = { P1.z, P2.z, P3.z };
	if ( !cramer3(a, b, c, d, A, B, C) )
	{
		printf("\Failed to create plain");
	};
}
void MyPlane::define(MyPoint P1, MyPoint P2, MyPoint P3)
{
	double a[] = { P1.x, P2.x, P3.x };
	double b[] = { P1.y, P2.y, P3.y };
	double c[] = { 1, 1, 1 };
	double d[] = { P1.z, P2.z, P3.z };
	if (!cramer3(a, b, c, d, A, B, C))
	{
		printf("\Failed to create plain");
	};
}
bool MyPlane::crossedByLine(MyLine line, MyPoint& crossing)
{
	MyPoint tempCrossing;
	double x[] = {line.getA(), line.getC(), this->A};
	double y[] = {-1, 0, this->B};
	double z[] = {0, -1, -1};
	double d[] = { -line.getB(), -line.getD(), -this->C };
	if ( cramer3(x,y,z,d, tempCrossing.x, tempCrossing.y, tempCrossing.z) )
	{
		crossing = tempCrossing;

		return true;
	}
	else return false;
}
void MyPlane::printInfo()
{
	printf("\nPlain:\nA = %lf\nB = %lf\nC = %lf\n", A, B, C);
}
MyPlane::~MyPlane(){}