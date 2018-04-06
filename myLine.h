#pragma once
class MyLine
{
private:
	double A, B, C, D;
public:
	MyLine();
	MyLine(MyPoint A, MyPoint B);
	~MyLine();
};

MyLine::MyLine(MyPoint P1, MyPoint P2)
{
	if (
		!cramer(P1.x, 1, P1.y, P2.x, 1, P2.y, A, B) ||
		!cramer(P1.x, 1, P1.z, P2.x, 1, P2.z, C, D)
	)
	{
		printf("\n Unable to calculate the line.");
		A = 0, B = 0, C = 0, D = 0;
	}
}