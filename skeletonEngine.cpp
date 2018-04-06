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