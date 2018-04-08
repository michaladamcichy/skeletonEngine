#pragma once
class Screen
{
private:
	int screenWidth;
	int screenHeight;
	std::vector <Edge> castedEdges;
public:
	Screen();
	Screen(int screenWidth, int screenHeight);
	void castEdges(World& world, Camera& camera);
	void drawCastedEdges(Renderer& renderer);
	~Screen();
};	

Screen::Screen(){}
Screen::Screen(int scrw, int scrH)
{
	screenWidth = scrw;
	screenHeight = scrH;
}
void Screen::castEdges(World& world, Camera& camera)
{
	castedEdges.clear();
	MyPlane currentCameraPlain = camera.getPlain();
	MyLine currentRayAS;
	MyLine currentRayBS;
	MyPoint crossingA;
	MyPoint crossingB;
	for (int index = 0; index < world.getEdgesCount(); index++)
	{
		currentRayAS.define( world.getEdge(index).getA(), camera.getS() );
		currentRayBS.define(world.getEdge(index).getB(), camera.getS());

		if ( currentCameraPlain.crossedByLine(currentRayAS, crossingA) &&
			 currentCameraPlain.crossedByLine(currentRayBS, crossingB) )
		{
			castedEdges.push_back({ crossingA, crossingB });
			printf("\n");
			crossingA.print();
			crossingB.print();
		}
	}
}
void Screen::drawCastedEdges(Renderer& renderer)
{
	for (int i = 0; i < castedEdges.size(); i++)
	{
		castedEdges[i].draw(renderer);
	}
}
Screen::~Screen() {}