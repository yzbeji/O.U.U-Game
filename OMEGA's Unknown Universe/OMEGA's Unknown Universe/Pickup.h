#pragma once
#include "raylib.h"
#include <string>
class Pickup
{
	protected:
		Texture2D Item;
		int X, Y;
		int current_Frame, current_Sprite;
		double Timer;
		bool Picked_UP;
	public:
		Pickup(const char*, const int, const int);
		~Pickup();
		bool get_Picked_UP() { return this->Picked_UP; }
		void set_Picked_UP() { this->Picked_UP = true; }
		int get_Y() const { return this->Y; }
		int get_X() const { return this->X; }
		virtual void Draw() = 0;
		virtual std::string Pickup_Type() = 0;
};