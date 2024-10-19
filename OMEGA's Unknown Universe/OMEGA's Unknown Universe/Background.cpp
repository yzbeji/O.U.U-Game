#include "Background.h"
#include <iostream>

Space_Background::Space_Background(void) {
	this->current_SpriteY = Background_Height - 800;
	this->Space = LoadTexture("C:\\Users\\Stefan\\Desktop\\Background.png");
}
void Space_Background::Draw(void)
{
	current_SpriteY += Y;
	if ((current_SpriteY - Y >= 0 and current_SpriteY >= -Y) or current_SpriteY == -800) {
		current_SpriteY = (current_SpriteY == -800) ? Background_Height - 800 : current_SpriteY;
		Rectangle Source = { 0, current_SpriteY, 800, 800 };
		Rectangle Destination = { 0, 0, 800, 800 };
		DrawTexturePro(Space, Source, Destination, Origin, 0.f, RAYWHITE);
	}
	else {
		int UpperPart_Y = Background_Height + current_SpriteY;
		int LowerPart_Y = 800 + current_SpriteY;
		Rectangle Lower_Source = { 0, 0, 800, LowerPart_Y };
		Rectangle Upper_Source = { 0, UpperPart_Y, 800, UpperPart_Y };
		Rectangle Lower_Destination = { 0, LowerPart_Y, 800, LowerPart_Y };
		Rectangle Upper_Destination = { 0, 0, 800, UpperPart_Y };
		DrawTexturePro(Space, Lower_Source, Lower_Destination, Origin, 0.f, RAYWHITE);
		DrawTexturePro(Space, Upper_Source, Upper_Destination, Origin, 0.f, RAYWHITE);
	}
}
Space_Background::~Space_Background() {
	UnloadTexture(Space);
}
