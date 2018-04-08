#pragma once
class MyPlain
{
/*
z = A*x + B*y + C
*/
private:
	double A, B, C;
public:
	MyPlain();
	MyPlain(MyPoint A, MyPoint B, MyPoint C);
	bool crossedByLine(MyLine line, MyPoint& crossing);
	void printInfo();
	~MyPlain();
};

MyPlain::MyPlain(){}
MyPlain::MyPlain(MyPoint P1, MyPoint P2, MyPoint P3)
{
	double a[] = {P1.x, P2.x, P3.x};
	double b[] = {P1.y, P2.y, P3.y};
	double c[] = {1, 1, 1};
	double d[] = { P1.z, P2.z, P3.z };
	cramer3(a, b, c, d, A, B, C);
}
bool MyPlain::crossedByLine(MyLine line, MyPoint& crossing)
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
void MyPlain::printInfo()
{
	printf("\nPlain:\nA = %lf\nB = %lf\nC = %lf\n", A, B, C);
}
MyPlain::~MyPlain(){}