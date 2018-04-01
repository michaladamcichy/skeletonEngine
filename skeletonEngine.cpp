#include<stdafx.h>
#include<config.h>

int main(int argc, char* argv[])
{
	MyPoint A(5, 6);
	MyPoint B(1, 2);
	A.print();
	B.print();
	printf("\n");

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