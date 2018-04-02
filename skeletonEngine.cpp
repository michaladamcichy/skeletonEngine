/*
Copyright by Michał Cichy
2018
*/
#include<stdafx.h>
#include<config.h>

int main(int argc, char* argv[])
{
	MyVector AB(2, 4), CD(-5, -10);
	if (AB <= CD) std::cout << "####";
	Config cfg;
	init_SDL();
	Window window(
		cfg.getWindowTitle(),
		cfg.getScreenWidth(),
		cfg.getScreenHeight());
	Renderer renderer(window, SDL_RENDERER_PRESENTVSYNC);
	renderer.clear();
	renderer.updateScreen();
	SDL_Delay(1000);
	quit_SDL();
	return 0;
}		