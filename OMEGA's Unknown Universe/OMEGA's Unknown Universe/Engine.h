#pragma once
#include "raylib.h"
#include <vector>
class Engine {
	private:
		std::vector < Texture2D > Engines;
		std::vector < Texture2D > EnginePower;
		const Vector2 Origin{ 0, 0 };
		Texture2D current_Engine;
		Texture2D current_EnginePower;
		int current_Frame;
		int current_Sprite;
	public:
		void Draw(float X, float Y);
		void Change_Engine(unsigned int N);
		Engine(void);
		~Engine(void);
};