#pragma once
#include "raylib.h"
class Shield
{
	private:
		Texture2D Protection;
		double Timer;
		int X, Y;
		int current_Frame, current_Sprite;
	public:
		Shield(const int, const int);
		~Shield();
		void Draw(const int, const int);
		double get_Timer() { return this->Timer; }
};