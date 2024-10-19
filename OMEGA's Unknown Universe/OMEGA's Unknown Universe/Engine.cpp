#include "Engine.h"

Engine::Engine(void)
{
	Engines.resize(4);
	EnginePower.resize(4);
	Engines[0] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Base Engine.png");
	Engines[1] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Burst Engine.png");
	Engines[2] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Big Pulse Engine.png");
	Engines[3] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Supercharged Engine.png");
	EnginePower[0] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Base Engine - Powering.png");
	EnginePower[1] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Burst Engine - Powering.png");
	EnginePower[2] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Big Pulse Engine - Powering.png");
	EnginePower[3] = LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Supercharged Engine - Powering.png");
	current_Engine = Engines[0];
	current_EnginePower = EnginePower[0];
	current_Sprite = current_Frame = 0;
}
Engine::~Engine(void) {
	Engines.clear();
	EnginePower.clear();
}
void Engine::Draw(const float X, const float Y) {
	if (current_Frame % 15 == 0 and current_Frame)
		current_Sprite++;
	if (current_Frame == 60)
		current_Frame = 0;
	Rectangle Source_Engine{ 0, 0, 48, 48 };
	Rectangle Source_EnginePower { current_Sprite * 48, 0, 48, 48 };
	const Rectangle Destination{ X, Y, 90, 90 };
	DrawTexturePro(current_Engine, Source_Engine, Destination, Origin, 0.f, RAYWHITE);
	DrawTexturePro(current_EnginePower, Source_EnginePower, Destination, Origin, 0.f, RAYWHITE);
	current_Frame++;
}
void Engine::Change_Engine(unsigned int N) {
	current_Engine = Engines[N];
	current_EnginePower = EnginePower[N];
}