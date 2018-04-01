#pragma once
struct Color
{
public:
	unsigned char R;
	unsigned char G;
	unsigned char B;
	unsigned char A = SDL_ALPHA_OPAQUE;
};

Color RED = { 255, 0, 0};
Color GREEN = { 0, 255, 0};
Color BLUE = { 0, 0, 255};
Color WHITE = {255, 255, 255};
Color BLACK = {0, 0, 0};