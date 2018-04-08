#pragma once
class Edge
{
public:
	MyPoint A, B;
	Edge();
	Edge(MyPoint A, MyPoint B);
	void define(MyPoint A, MyPoint B);
	MyPoint getA();
	MyPoint getB();
	void draw(Renderer& renderer);
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
MyPoint Edge::getA()
{
	return A;
}
MyPoint Edge::getB()
{
	return B;
}
void Edge::printInfo()
{
	A.print();
	printf("--");
	B.print();
}
void Edge::draw(Renderer& renderer)
{
	drawSegment(renderer, A, B);
}
Edge::~Edge()
{
}