#include "Auto-Cannon.h"
#include "Asteroid.h"
#include "Collision.h"
#include <vector>
#include <cmath>
AutoCannon::AutoCannon(const int X, const int Y) : current_Weapon(LoadTexture("C:\\Users\\Stefan\\Desktop\\Weapon - Auto - Cannon.png")), current_X(X), current_Y(Y), current_Sprite(0), current_Frame(0), Shoot(false), Delay(0) { }
AutoCannon::~AutoCannon()
{
	UnloadTexture(current_Weapon);
	Bullets.clear();
}
void AutoCannon::Draw(const float X, const float Y)
{
	if (IsKeyPressed(KEY_S) and !Shoot and GetTime() >= 10.5 and abs(Delay - GetTime()) > 0.5)
	{
		Bullets.push_back(new Bullet_AutoCannon(X + 7, Y));
		Bullets.push_back(new Bullet_AutoCannon(X + 37, Y));
		Shoot = true;
		Delay = GetTime();
	}
	if (current_Frame % 3 == 0 and current_Frame != 0 and current_Frame <= 21)
		current_Sprite++;
	if (current_Frame == 21 and Shoot)
		current_Sprite = current_Frame = 0, Shoot = false;
	const Vector2 Origin = { 0, 0 };
	const Rectangle Source_Weapon = { current_Sprite * 48, 0, 48, 48 };
	const Rectangle Destination_Weapon = { X, Y, 90, 90 };
	DrawTexturePro(current_Weapon, Source_Weapon, Destination_Weapon, Origin, 0.f, RAYWHITE);
	for (std::vector < Bullet_AutoCannon* >::iterator Bullet = Bullets.begin(); Bullet != Bullets.end();)
	{
		if (Bullet != Bullets.begin() and GetTime() >= 10.5)
		{
			std::vector < Bullet_AutoCannon* >::iterator last_Bullet = Bullet;
			last_Bullet--;
			if ((*last_Bullet)->get_Y() <= 690)
				(*Bullet)->Draw();  
		}
		else if(GetTime() >= 10.5)
			(*Bullet)->Draw();
		if ((*Bullet)->get_Y() < -46 or (*Bullet)->get_Fired() == true)
		{
			delete (*Bullet);
			Bullet = Bullets.erase(Bullet);
		}
		else
			Bullet++;
	}
	if (Shoot and GetTime() >= 10.5)
		current_Frame++;	
}
void AutoCannon::Checker(Asteroid*& Rock)
{
	for (std::vector < Bullet_AutoCannon* >::iterator Bullet = Bullets.begin(); Bullet != Bullets.end(); Bullet++)
	{
		if (Bullseye((*Bullet), Rock) == true and Rock->get_Destroyed() == false)	
			(*Bullet)->set_Fired(), Rock->set_Destroyed();
	}
}

