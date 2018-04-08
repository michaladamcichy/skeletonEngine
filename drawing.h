#pragma once

void drawSegment(Renderer& renderer, MyPoint A, MyPoint B, Color color = { 255, 255, 255, 255 } )
{
	renderer.setDrawingcolor(color);
	SDL_RenderDrawLine(renderer.getPointer(), A.x, A.y, B.x, B.y);
	/*printf("\n");
	A.print();
	B.print();*/
}