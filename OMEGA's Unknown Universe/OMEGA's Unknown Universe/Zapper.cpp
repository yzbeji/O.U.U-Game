#include "Zapper.h"
#include <cmath>
Zapper::Zapper(const int X, const int Y) : current_Weapon(LoadTexture("C:\\Users\\Stefan\\Desktop\\Weapon - Zapper.png")), X(X), Y(Y), current_Frame(0), current_Sprite(0), Shoot(false), Delay(0), Timer(GetTime()) { }
Zapper::~Zapper()
{
	UnloadTexture(current_Weapon);
	left_Zaps.clear();
	right_Zaps.clear();
}
void Zapper::Draw(const int X, const int Y)
{
	const Vector2 Origin = { 0, 0 };
	if (IsKeyPressed(KEY_S) and !Shoot and abs(GetTime() - Delay) > 5)
	{
		int recursive_Y = 700;
		while (recursive_Y > -30)
		{
			left_Zaps.push_back(new Bullet_Zapper(recursive_Y));		
			right_Zaps.push_back(new Bullet_Zapper(recursive_Y));		
			recursive_Y -= 60;
		}
		Shoot = true;
		Delay = GetTime();
	}
	if (current_Frame % 6 == 0 and current_Frame != 0 and current_Frame <= 84)
		current_Sprite++;
	if (current_Frame == 84 and Shoot)
		current_Frame = current_Sprite = 0, Shoot = false;
	const Rectangle Source_Weapon = { current_Sprite * 48, 48, 48, 48 };
	const Rectangle Destination_Weapon = { X, Y, 90, 90 };
	DrawTexturePro(current_Weapon, Source_Weapon, Destination_Weapon, Origin, 0.f, RAYWHITE);
	if (GetTime() - Delay >= 1.5)
	{
		for (std::vector < Bullet_Zapper* >::iterator left_Zap = left_Zaps.begin(); left_Zap != left_Zaps.end();)
		{
			if (abs((*left_Zap)->get_Timer() - GetTime()) > 4)
			{
				delete (*left_Zap);
				left_Zap = left_Zaps.erase(left_Zap);
			}
			else
			{
				(*left_Zap)->Draw(X);
				left_Zap++;
			}
		}
		for (std::vector < Bullet_Zapper* >::iterator right_Zap = right_Zaps.begin(); right_Zap != right_Zaps.end();)	
		{
			if (abs((*right_Zap)->get_Timer() - GetTime()) > 4)	
			{
				delete (*right_Zap);	
				right_Zap = right_Zaps.erase(right_Zap);
			}
			else
			{
				(*right_Zap)->Draw(X + 30);
				right_Zap++;	
			}

		}
	}
	if (Shoot)
		current_Frame++;
}

void Zapper::Checker(Asteroid*& Rock, int X)
{
	for (std::vector < Bullet_Zapper* >::iterator left_Zap = left_Zaps.begin(); left_Zap != left_Zaps.end(); left_Zap++)
		if (Bullseye((*left_Zap), Rock, X) and GetTime() - Delay >= 1.5)	
			Rock->set_Destroyed();
	for (std::vector < Bullet_Zapper* >::iterator right_Zap = right_Zaps.begin(); right_Zap != right_Zaps.end(); right_Zap++)			
		if (Bullseye((*right_Zap), Rock, X) and GetTime() - Delay >= 1.5)	
			Rock->set_Destroyed();
}

