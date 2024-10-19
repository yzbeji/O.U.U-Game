#pragma once
#include "raylib.h"
#include "Engine.h"
#include "Auto-Cannon.h"
#include <vector>

class Spaceship {
	private:
		unsigned int HP;
		const Font HP_Font = LoadFont("C:\\Users\\Stefan\\Desktop\\Countdown Font.ttf");
		std::vector < Texture2D > current_State;
		Texture2D current_SpaceshipSprite;
		Engine Spaceship_Engine;
		const Vector2 Origin = { 0, 0 };
		const Rectangle Source = { 0, 0, 48, 48 };
		const int X = 5;
		int current_X, current_Y = 830;
	public:
		Spaceship(void);
		~Spaceship(void);
		void Draw(void);
		int get_X() const { return this->current_X; }
		int get_Y() const { return this->current_Y; }
		void set_HP() { if (this->HP > 0) this->HP -= 5; }
		unsigned int get_HP() const { return this->HP; }
};