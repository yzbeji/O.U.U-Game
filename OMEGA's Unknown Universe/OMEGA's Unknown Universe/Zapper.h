#pragma once
#include "raylib.h"
#include "Bullet_Zapper.h"
#include "Asteroid.h"
#include "Collision.h"
#include <vector>

class Zapper
{
	private:
		Texture2D current_Weapon;
		std::vector < Bullet_Zapper* > left_Zaps;
		std::vector < Bullet_Zapper* > right_Zaps;
		int X, Y;
		int current_Frame;
		int current_Sprite;
		bool Shoot;
		int Delay;
		double Timer;
	public:
		Zapper(const int, const int);
		~Zapper();
		double get_Timer() const { return this->Timer; }
		void Draw(const int, const int); 
		void Checker(Asteroid*&, int);
};