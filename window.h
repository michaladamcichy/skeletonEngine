class Window
{
private:
	SDL_Window * window;
public:
	Window(const char* title, int scrW, int scrH, int flags);
	SDL_Window* getPointer()
	{
		return window;
	}
	~Window();
};

Window::Window(const char* title, int scrW, int scrH, int flags = SDL_WINDOW_SHOWN)
{
	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		scrW,
		scrH,
		flags
	);
	if (window == NULL)
	{
		printf("\nCouldn't create window: %s", SDL_GetError());
	}
}
Window::~Window()
{
	SDL_DestroyWindow(window);
}