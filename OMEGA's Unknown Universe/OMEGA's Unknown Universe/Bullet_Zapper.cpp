#include "Bullet_Zapper.h"

Bullet_Zapper::Bullet_Zapper(int Y) : Zap(LoadTexture("C:\\Users\\Stefan\\Desktop\\Bullet - Zapper.png")), Y(Y), current_Sprite(0), current_Frame(0), Timer(GetTime()), Shoot(false) { }

Bullet_Zapper::~Bullet_Zapper()
{
	UnloadTexture(Zap);
}

void Bullet_Zapper::Draw(const int X)
{
	const Vector2 Origin = { 0, 0 };
	if (current_Frame % 7 == 0 and current_Frame != 0)
		current_Sprite++;
	if (current_Frame == 56)
		current_Frame = 0;
	const Rectangle Source = { current_Sprite * 32, 32, 32, 32 };
	const Rectangle Destination = { X, this->Y, 60, 60 };
	DrawTexturePro(Zap, Source, Destination, Origin, 0.f, RAYWHITE);
	current_Frame ++;
}


