#pragma once
class Renderer
{
	SDL_Renderer* renderer;
public:
	Renderer();
	Renderer(Window& window, int flags);
	bool create(Window& window, int flags);
	void setDrawingcolor(Color color = { 0,0,0,0 });
	void clear(Color color = { 0,0,0,0 });
	void updateScreen();
	SDL_Renderer* getPointer();
	~Renderer();
};

Renderer::Renderer() 
{
}

Renderer::Renderer(Window& window, int flags = 0)
{
	renderer = SDL_CreateRenderer(window.getPointer(), NULL, SDL_RENDERER_ACCELERATED | flags);
	if (renderer != NULL)
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"))
			printf("\nCannot set hint texture filtering: %s\n", SDL_GetError());
		if (0 > SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND))
		{
			printf("\nCouldn't set blend mode: %s", SDL_GetError());
		}
	}
	this->clear();
	this->updateScreen();
}

bool Renderer::create(Window& window, int flags = 0)
{
	renderer = SDL_CreateRenderer(window.getPointer(), NULL, SDL_RENDERER_ACCELERATED | flags);
	if (renderer == NULL)
	{
		return false;
	}
	else
	{
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "2"))
			printf("\nCannot set hint texture filtering: %s\n", SDL_GetError());
		if (0 > SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND))
		{
			printf("\nCouldn't set blend mode: %s", SDL_GetError());
		}
		return true;
	}
}

SDL_Renderer* Renderer::getPointer()
{
	return renderer;
}
void Renderer::setDrawingcolor(Color color)
{
	SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
}
void Renderer::clear(Color color)
{
	SDL_SetRenderDrawColor(renderer, color.R, color.G, color.B, color.A);
	SDL_RenderClear(renderer);
}
void Renderer::updateScreen()
{
	SDL_RenderPresent(renderer);
}

Renderer::~Renderer()
{
	SDL_DestroyRenderer(renderer);
}


