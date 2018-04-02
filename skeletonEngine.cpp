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
		cfg.getCameraLengthMultiplier*cfg.getScreenWidth()
	);
	SDL_Delay(1000);
	quit_SDL();
	return 0;
}		