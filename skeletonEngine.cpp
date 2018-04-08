/*
Copyright by Michał Cichy
2018
*/
#include<stdafx.h>
#include<config.h>
#include<world.h>
#include<camera.h>

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
	////Tests
	MyPoint A(-8,3,5);
	MyPoint B(2,-1,10);
	MyPoint C(-2,6,15);
	MyPlain plain(A, B, C);
	plain.printInfo();
	MyPoint E(3,1,7);
	MyPoint F(-1, 0, 5);
	MyLine line(E,F);
	printf("\n##");
	MyPoint inter;
	if (plain.crossedByLine(line, inter))
	{
		inter.print();
	}
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
		renderer.updateScreen();
	}
	////
	quit_SDL();
	return 0;
}		