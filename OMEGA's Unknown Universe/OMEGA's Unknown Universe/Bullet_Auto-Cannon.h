#pragma once
#include "raylib.h"
#include <stdlib.h>

class Bullet_AutoCannon
{
	private:
		Texture2D Bullet;
		bool Fired;
		unsigned int current_Frame;
		unsigned int current_Sprite;
		int Y;
		int X;
	public:
		Bullet_AutoCannon(int, int);
		~Bullet_AutoCannon();
		void Draw();
		int get_Y() const;
		int get_X() const;
		bool get_Fired() { return this->Fired; }
		void set_Fired() { this->Fired = true; }
};