#pragma once
#include "raylib.h"
class Asteroid
{
	private:
		const Texture2D Idle;
		const Texture2D Explode;
		const Texture2D Flames;
		int flames_Frame, flames_Sprite;
		int explode_Frame, explode_Sprite;
		int X, Y;
		bool Destroyed;
		double Timer;
	public:
		Asteroid(const int, const int);
		~Asteroid();
		void Boom();
		void Fall();
		int get_X() const { return this->X; }
		int get_Y() const { return this->Y; }
		double get_Timer() const { return this->Timer; }
		bool get_Destroyed() const { return this->Destroyed; }
		void set_Destroyed() { this->Destroyed = true; }
};