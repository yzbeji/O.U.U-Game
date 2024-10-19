#pragma once
#include "raylib.h"

class Bullet_Zapper
{
	private:
		Texture2D Zap;
		int current_Frame, current_Sprite;
		int Y;
		double Timer;
		bool Shoot;
	public:
		Bullet_Zapper(int);
		~Bullet_Zapper();
		void Draw(const int);
		double get_Timer() const { return this->Timer; }
		int get_Y() const { return this->Y; }
};