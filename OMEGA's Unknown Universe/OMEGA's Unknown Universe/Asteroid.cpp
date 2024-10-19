#include "Asteroid.h"

Asteroid::Asteroid(const int X, const int Y) : X(X), Y(Y), Idle(LoadTexture("C:\\Users\\Stefan\\Desktop\\Asteroid.png")), Flames(LoadTexture("C:\\Users\\Stefan\\Desktop\\Asteroid - Flame.png")), Explode(LoadTexture("C:\\Users\\Stefan\\Desktop\\Asteroid - Explode.png")), Timer(-1) 
{
	flames_Frame = flames_Sprite = 0;
	explode_Frame = explode_Sprite = 0;
	Destroyed = false;
}

Asteroid::~Asteroid()
{
	UnloadTexture(Idle);
	UnloadTexture(Flames);
}

void Asteroid::Fall()
{
	if (flames_Frame % 8 == 0 and flames_Frame != 0)
		flames_Sprite++;
	if (flames_Frame == 24)
		flames_Frame = 0;
	const Vector2 Origin = { 0, 0 };
	const Rectangle Source_Flames = { flames_Sprite * 96, 96, 96, 96 };	
	const Rectangle Destination_Flames = { this->X, this->Y + 96, 96, 96 };	
	DrawTexturePro(Flames, Source_Flames, Destination_Flames, Origin, 270.f, RAYWHITE);	
	DrawTexturePro(Idle, { 0, 0, 96, 96 }, { (float)this->X, (float)this->Y, 96, 96 }, Origin, 0.f, RAYWHITE);	
	flames_Frame++;
	this->Y += 5;
}

void Asteroid::Boom()
{
	if (Timer == -1)
		Timer = GetTime();
	Destroyed = true;
	if (explode_Frame % 4 == 0 and explode_Frame != 0 and explode_Frame != 32)
		explode_Sprite++;
	if (explode_Frame == 32)
		explode_Sprite = 8;
	const Vector2 Origin = { 0, 0 };
	const Rectangle Source = { explode_Sprite * 96, 96, 96, 96 };
	const Rectangle Destination = { this->X, this->Y, 96, 96 };
	DrawTexturePro(Explode, Source, Destination, Origin, 0.f, RAYWHITE);
	if(explode_Frame < 32)
		explode_Frame++;
}
