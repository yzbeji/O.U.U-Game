#pragma once
#include "raylib.h"
#include "Bullet_Auto-Cannon.h"
#include "Asteroid.h"
#include <vector>

class AutoCannon
{
	private:
		Texture2D current_Weapon;
		std::vector < Bullet_AutoCannon* > Bullets;
		unsigned int current_Frame;
		unsigned int current_Sprite;
		int current_X;
		int current_Y;
		bool Shoot;
		double Delay;
	public:
		AutoCannon(const int, const int);
		~AutoCannon();
		void Draw(const float X, const float Y);
		void Checker(Asteroid*&);
		
};