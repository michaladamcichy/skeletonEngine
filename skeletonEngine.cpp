/*
Copyright by Michał Cichy
2018
*/
#include<stdafx.h>
#include<config.h>
#include<world.h>
#include<camera.h>
#include<screen.h>

int main(int argc, char* argv[])
{
	Config cfg;
	init_SDL();
	Window window(
		cfg.getWindowTitle(),
		cfg.getScreenWidth(),
		cfg.getScreenHeight()
	);
	Renderer renderer(window, SDL_RENDERER_PRESENTVSYNC);
	World world(cfg.getWorldFileName());
	Camera camera(
		cfg.getScreenWidth(),
		cfg.getScreenHeight(),
		cfg.getCameraLength()
	);
	Screen screen(cfg.getScreenWidth(), cfg.getScreenHeight());
	////Tests
	//MyPlane plain({ 1,2,3 }, { 2,3,4 }, { 4,5,6 });
	//X.print();
	/*double A[4][4] = 
	{
		4,3,2,99 , 99,6,7,100 , 12,99,10,100,100,99,99,99
	};*/
	double a[4] = { 1,1,1,2 };
	double b[4] = { 1,-1,-1,1 };
	double c[4] = { 1,1,-1,1 };
	double d[4] = { 1, 1,1,-1 };
	double e[4] = { 2,-2,-2,5 };
	double x, y, z, w;
	if ( cramer4(a,b,c,d,e,x,y,z, w) )
	{
		printf("\n####%lf %lf %lf %lf\n", x, y, z,w);
	}
	//std::cout << "%%%%%%" << determinant(A);
	////
	SDL_Event event;
	bool exit = false;
	while (!exit)
	{
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_QUIT)
			{
				exit = true;
			}
			else
			{
				///
			}
		}
		renderer.clear();
		screen.castEdges(world, camera);
		//screen.drawCastedEdges(renderer);
		renderer.updateScreen();
		exit = true;
	}
	////
	quit_SDL();
	return 0;
}		