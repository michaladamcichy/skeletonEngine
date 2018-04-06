#pragma once
#include<edge.h>
class World
{
private:
	std::vector <Edge> edges;
public:
	World();
	World(const char* fileName);
	int addEdge(Edge edge);
	Edge& getEdge(int index);
	bool removeEdge(int index);
	void printInfo();
	~World();
};

World::World()
{
}
World::World(const char* fileName)
{
	std::ifstream input;
	input.open(fileName);
	if (input.good() && !isFileEmpty(fileName))
	{
		double x, y, z;
		MyPoint A, B;
		Edge edge;
		while ( !input.eof() )
		{
			input >> x >> y >> z;
			A.define(x, y, z);
			input >> x >> y >> z;
			B.define(x, y, z);
			edge.define(A, B);
			addEdge(edge);
		}
		printf("\n---------------------\nWorld successfully loaded.");
		this->printInfo();
	}
	else
	{
		printf("\nUnable to load the world. There is a problem with file %s.", fileName);
	}
	input.close();
}
int World::addEdge(Edge edge)
{
	edges.push_back(edge);
	return edges.size();
}
Edge& World::getEdge(int index)
{
	return edges[index];
}
bool World::removeEdge(int index)
{
	if (0 <= index && index < edges.size())
	{
		edges.erase(edges.begin() + index);
		return true;
	}
	return false;
}
void World::printInfo()
{
	printf("\nWorld contains %d edges", edges.size());
	for (int i = 0; i < edges.size(); i++)
	{
		printf("\n");
		edges[i].printInfo();
	}
}
World::~World()
{
}
