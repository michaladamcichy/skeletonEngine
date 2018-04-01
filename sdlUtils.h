#pragma once
#include<colors.h>
#include<window.h>
#include<renderer.h>
bool init_SDL()
{
     if (0 > SDL_Init(SDL_INIT_EVERYTHING))
     {
		 printf("\nCouldn't start SDL : %s", SDL_GetError());
		 return false;
     }
     if(0 > IMG_Init(IMG_INIT_PNG))
     {
		 printf("\nCouldn't start SDL_IMG : %s", IMG_GetError());
		 return false;
	 };
	 if (0 > Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 6, 2048 ))
     {
		 printf("\nCouldn't open Mixer: %s", Mix_GetError());return false;
     }
	 if (0 > TTF_Init())
	 {
		 printf("\nUnable to open ttf. %s", TTF_GetError());
		 return false;
	 }
    return true;
}

void quit_SDL()
{
    Mix_Quit();
    IMG_Quit();
	TTF_Quit();
    SDL_Quit();
}

class MyText
{
private:
	SDL_Texture * texture;
	TTF_Font * font;
public:
	MyText()
	{
		font = TTF_OpenFont("font.ttf", 28);
		if (font == NULL)
		{
			printf("\n Unable to load the font. %s", TTF_GetError());
		}
	}
	MyText(std::string fontName, int size)
	{
		font = TTF_OpenFont(fontName.c_str(), size);
		if (font == NULL)
		{
			printf("\n Unable to load the font. %s", TTF_GetError());
		}
	}
	~MyText()
	{
		SDL_DestroyTexture(texture);
	}
	void create(std::string fontName, int size)
	{
		font = TTF_OpenFont(fontName.c_str(), size);
		if (font == NULL)
		{
			printf("\n Unable to load the font. %s", TTF_GetError());
		}
	}
	void update(Renderer& renderer, std::string text, SDL_Color color = {0,0,0,0})
	{
		SDL_Surface* surf;
		surf = TTF_RenderText_Solid(font, text.c_str(), { 255, 255, 255, 255 });
		texture = SDL_CreateTextureFromSurface(renderer.getPointer(), surf);
		SDL_FreeSurface(surf);
	}
	void render(Renderer& renderer, SDL_Rect* out)
	{
		SDL_RenderCopy(renderer.getPointer(), texture, NULL, out);
	}
};

class MyTexture
{
 private:

        SDL_Rect rect;
        SDL_Texture* texture;
 public:

        void createFromFile(Renderer& renderer, std::string path)
        {
            SDL_Surface* surface;
            surface = IMG_Load(path.c_str());
            if (surface == NULL)
            {
                printf("\n%s", IMG_GetError());
            }
            rect = {0, 0, surface->w, surface->h};
            texture = SDL_CreateTextureFromSurface(renderer.getPointer(), surface);
            if (texture == NULL)
            {
                printf("\n%s", SDL_GetError());
            }
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
            SDL_FreeSurface(surface);
        }

        void createBlank(Renderer& renderer, int w, int h, int Flags=NULL)
        {
            texture = SDL_CreateTexture(renderer.getPointer(), SDL_PIXELFORMAT_RGBA8888,
                                         Flags, w, h);
            if (texture == NULL)
            {
                printf("\n%s", SDL_GetError());
            }
            rect = {0,0, w, h};
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
        }

        void render(Renderer& renderer, SDL_Rect* rectIn=NULL, SDL_Rect* rectOut=NULL)
        {
            if (rectIn == NULL) rectIn = &rect;
            if (rectOut == NULL) rectOut = &rect;
            SDL_RenderCopy(renderer.getPointer(), texture, rectIn, rectOut);
        }

        unsigned char * getPixelData(Renderer& renderer)
        {
            unsigned char * pixelData = new unsigned char [rect.w*rect.h*4];
            SDL_RenderClear(renderer.getPointer());
            SDL_RenderCopy(renderer.getPointer(), texture, &rect, &rect);
            if(0<SDL_RenderReadPixels(renderer.getPointer(), &rect, SDL_PIXELFORMAT_RGBA8888, pixelData, rect.w*4))
            printf("\n%s", SDL_GetError());
            return pixelData;
        }
        void loadPixelData(unsigned char * pixelData)
        {
            void* pixels;
            int pitch = rect.w * 4;
            SDL_LockTexture(texture, &rect, &pixels, &pitch);
            memcpy( pixels, &pixelData[0], rect.w*rect.h*4 );
            SDL_UnlockTexture(texture);
        }
        void setAsRenderTarget(Renderer& renderer)
        {
            SDL_SetRenderTarget(renderer.getPointer(), texture);
        }
        void setAlpha(unsigned char alpha)
        {
            SDL_SetTextureAlphaMod(texture, alpha);
        }
		void setBrightness(unsigned char brightness)
		{
			SDL_SetTextureColorMod(texture, brightness, brightness, brightness);
		}
		int getX()
        {
            return rect.x;
        }
        int getY()
        {
            return rect.y;
        }
        SDL_Rect getRect()
        {
            return rect;
        }
        void setX(int inX)
        {
            rect.x = inX;
        }
        void setY(int inY)
        {
            rect.y = inY;
        }
        SDL_Texture* getTexture()
        {
            return texture;
        }
        int getW()
        {
            return rect.w;
        }
        int getH()
        {
            return rect.h;
        }
        ~MyTexture()
        {
            SDL_DestroyTexture(texture);
        }
};

enum AnimatedTextureEnums
{
	DEFAULT_ANIMATED_TEXTURE,
	BIG_ANIMATED_TEXTURE
};

enum SwitchingFrames
{
	SWITCH_FRAMES_AUTO,
	SWITCH_FRAMES_MANUALLY
};

class AnimatedTexture
{
    private:
		int type;
		int switchFrames;
        SDL_Rect rect;
		SDL_Texture * * textures;
        int frameWidth;
        int frameHeight;
        int currentFrame=0;
        int framesCount;
        int speed;
 public:
        void createFromFile(Renderer& renderer, std::string path, int inFramesCount=1, int inSpeed=1,
			int inType = DEFAULT_ANIMATED_TEXTURE, int inSwitchFrames = SWITCH_FRAMES_AUTO)
        {
			type = inType;
			switchFrames = inSwitchFrames;
			framesCount = inFramesCount;
			speed = inSpeed;
			SDL_Surface* surface = NULL;
            
			if (type == DEFAULT_ANIMATED_TEXTURE)
			{
				surface = IMG_Load(path.c_str());
				if (surface == NULL)
				{
					printf("\n%s", IMG_GetError());
				}
				rect = { 0, 0, surface->w, surface->h };
				textures = new SDL_Texture* [1];
				textures[0] = SDL_CreateTextureFromSurface(renderer.getPointer(), surface);
				if (textures[0] == NULL)
				{
					printf("\n%s", SDL_GetError());
				}
				SDL_SetTextureBlendMode(textures[0], SDL_BLENDMODE_BLEND);
				SDL_FreeSurface(surface);
				frameWidth = rect.w;
				frameHeight = rect.h / framesCount;
			}
			else if (type == BIG_ANIMATED_TEXTURE)
			{
				textures = new SDL_Texture*[framesCount];
				int pos = path.find(".png");
				if (pos == path.size() - 4)
				{
					path.erase(pos, 4);
				}
				std::cout << "\nLoading bigTexture! Selected path: " << path;
				std::string specPath;

				for (int i = 0; i < framesCount; i++)
				{
					SDL_FreeSurface(surface);
					specPath = "";
					specPath.append(path);
					specPath.append("/");
					specPath.append(lastWordFromPath(path));
					specPath.append(std::to_string(i));
					specPath.append(".png");
					surface = IMG_Load(specPath.c_str());
					if (surface == NULL)
					{
						printf("\n%s", IMG_GetError());
					}
					rect = { 0, 0, surface->w, surface->h };
					textures[i] = SDL_CreateTextureFromSurface(renderer.getPointer(), surface);
					if (textures[i] == NULL)
					{
						printf("\n%s", SDL_GetError());
					}
					SDL_SetTextureBlendMode(textures[i], SDL_BLENDMODE_BLEND);
				}
				rect = { 0, 0, surface->w, surface->h };
				SDL_FreeSurface(surface);
				frameWidth = rect.w;
				frameHeight = rect.h;
			}
			else
			{
				printf("\nWrong animated texture format");
			}
        }
		void render(Renderer& renderer, SDL_Rect* rectInPointer = NULL, SDL_Rect* rectOutPointer = NULL)
        {
			SDL_Rect rectIn, rectOut;

			if ( rectInPointer == NULL )
			{
				rectIn = { 0, 0, frameWidth, frameHeight };
			}
			else
			{
				rectIn = *rectInPointer;
			}
			if ( rectOutPointer == NULL)
			{
				rectOut = { 0,0,frameWidth, frameHeight };
			}
			else
			{
				rectOut = *rectOutPointer;
			}

			if (type == DEFAULT_ANIMATED_TEXTURE)
			{
				rectIn.y = currentFrame / speed * frameHeight;
				SDL_RenderCopy(renderer.getPointer(), textures[0], &rectIn, &rectOut);
			}
			else if (type == BIG_ANIMATED_TEXTURE)
			{
				SDL_RenderCopy(renderer.getPointer(), textures[currentFrame/speed], &rectIn, &rectOut);
			}
			if ( switchFrames == SWITCH_FRAMES_AUTO)
			{
				nextFrame();
			}
		}
		void nextFrame()
		{
			currentFrame++;
			if ((currentFrame / speed) >= framesCount) currentFrame = 0;
		}
        void setAlpha(unsigned char alpha)
        {
			if (type == DEFAULT_ANIMATED_TEXTURE)
			{
				SDL_SetTextureAlphaMod(textures[0], alpha);
			}
			else if (type == BIG_ANIMATED_TEXTURE)
			{
				for (int i = 0; i < framesCount; i++)
				{
					SDL_SetTextureAlphaMod(textures[i], alpha);
				}
			}
        }
		void setBrightness(unsigned char brightness)
		{
			if (type == DEFAULT_ANIMATED_TEXTURE)
			{
				SDL_SetTextureColorMod(textures[0], brightness, brightness, brightness);
			}
			else if (type == BIG_ANIMATED_TEXTURE)
			{
				for (int i = 0; i < framesCount; i++)
				{
					SDL_SetTextureColorMod(textures[i], brightness, brightness, brightness);
				}
			}
		}
        int getX()
        {
            return rect.x;
        }
        int getY()
        {
            return rect.y;
        }
        SDL_Rect getRect()
        {
            return rect;
        }
        void setX(int inX)
        {
            rect.x = inX;
        }
        void setY(int inY)
        {
            rect.y = inY;
        }
        SDL_Texture *getTexture(int index = 0)
        {
			if (type == DEFAULT_ANIMATED_TEXTURE)
			{
				return textures[0];
			}
			else if (type == BIG_ANIMATED_TEXTURE && index >= 0 && index < framesCount)
			{
				return textures[index];
			}
			else
			{
				return NULL;
			}
        }
        int getW()
        {
            return rect.w;
        }
        int getH()
        {
            return rect.h;
        }
        int getFrameWidth()
        {
            return frameWidth;
        }
        int getFrameHeight()
        {
            return frameHeight;
        }
        int getFramesCount()
        {
            return framesCount;
        }
        ~AnimatedTexture()
        {
			if (type == DEFAULT_ANIMATED_TEXTURE)
			{
				SDL_DestroyTexture(textures[0]);
			}
			else if (type == BIG_ANIMATED_TEXTURE)
			{
				for (int i = 0; i < framesCount; i++)
				{
					SDL_DestroyTexture(textures[i]);
				}
			}
			delete[] textures;
        }
};