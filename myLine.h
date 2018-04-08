#pragma once
class MyLine
{
private:
	double A, B, C, D;
public:
	MyLine();
	MyLine(MyPoint A, MyPoint B);
	void define(MyPoint A, MyPoint B);
	bool containsPoint(MyPoint point);
	double getA();
	double getB();
	double getC();
	double getD();
	void printInfo();
	~MyLine();
};

MyLine::MyLine(){}
MyLine::~MyLine(){}
MyLine::MyLine(MyPoint P1, MyPoint P2)
{
	printf("\nCreating a line from points");
	P1.print();
	printf(" and ");
	P2.print();
	if (
		!cramer(P1.x, 1, P1.y, P2.x, 1, P2.y, A, B) ||
		!cramer(P1.x, 1, P1.z, P2.x, 1, P2.z, C, D)
	)
	{
		printf("\n Unable to calculate the line.");
		A = 0, B = 0, C = 0, D = 0;
	}
}
bool MyLine::containsPoint(MyPoint point)
{
	/*printf("\n");
	std::cout << point.y << " " << A * point.x + B;
	std::cout <<"\n"<< point.z << " " << C * point.x + D;*/
	if ( roundCent(point.y) == roundCent(A * point.x + B) &&
		roundCent(point.z) == roundCent(C * point.x + D))
	{
		return true;
	}
	else
		return false;
}
void MyLine::printInfo()
{
	printf("\n Line attributes: A = %lf\n B = %lf\nC = %lf\nD = %lf", A, B, C, D);
}
double MyLine::getA()
{
	return A;
}
double MyLine::getB()
{
	return B;
}
double MyLine::getC()
{
	return C;
}
double MyLine::getD()
{
	return D;
}
void MyLine::define(MyPoint P1, MyPoint P2)
{
	/*
	printf("\nCreating a line from points");
	P1.print();
	printf(" and ");
	P2.print();
	*/
	if (
		!cramer(P1.x, 1, P1.y, P2.x, 1, P2.y, A, B) ||
		!cramer(P1.x, 1, P1.z, P2.x, 1, P2.z, C, D)
		)
	{
		printf("\n Unable to calculate the line.");
		A = 0, B = 0, C = 0, D = 0;
	}
}