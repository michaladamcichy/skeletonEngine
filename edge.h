#pragma once
class Edge
{
public:
	MyPoint A, B;
	Edge();
	Edge(MyPoint A, MyPoint B);
	void define(MyPoint A, MyPoint B);
	void printInfo();
	~Edge();
};

Edge::Edge()
{
}
Edge::Edge(MyPoint inA, MyPoint inB)
{
	A = inA;
	B = inB;
}
void Edge::define(MyPoint inA, MyPoint inB)
{
	A = inA;
	B = inB;
}
void Edge::printInfo()
{
	A.print();
	printf("--");
	B.print();
}
Edge::~Edge()
{
}