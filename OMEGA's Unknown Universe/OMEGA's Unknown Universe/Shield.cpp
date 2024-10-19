#include "Shield.h"

Shield::Shield(const int X, const int Y) : X(X), Y(Y), Protection(LoadTexture("C:\\Users\\Stefan\\Desktop\\Shield.png")), current_Frame(0), current_Sprite(0), Timer(GetTime()) { }

Shield::~Shield()
{
	UnloadTexture(Protection);
}

void Shield::Draw(const int X, const int Y)
{
	const Vector2 Origin = { 0, 0 };
	if (current_Frame % 5 == 0 and current_Frame != 0)
		current_Sprite++;
	if (current_Frame == 60)
		current_Frame = 0;
	const Rectangle Source = { current_Sprite * 64, 64, 64, 64 };
	const Rectangle Destination = { X, Y + 10, 85, 85 };
	DrawTexturePro(Protection, Source, Destination, Origin, 0.f, RAYWHITE);
	current_Frame++;
}


