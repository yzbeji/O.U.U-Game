#pragma once
#pragma once
#include "raylib.h"
#include "Background.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Shield.h"
#include "Zapper.h"
#include "Pickup_Shield.h"
#include "Pickup_Zapper.h"
#include <random>
#include <vector>
#include "Collision.h"
class Game
{
private:
	Space_Background Background;
	std::vector < Asteroid* > Asteroids;
	std::vector < Pickup* > Pickups;
	Shield* Protection = nullptr;
	Zapper* Zap = nullptr;
	const Font Theme_Font;
	Spaceship Rocket;
	AutoCannon* Auto_Cannon;
	unsigned long long High_Score;
	bool Finished;
	double Timer;
public:
	Game();
	~Game();
	void HandleInput();
	bool get_Finished() const { return this->Finished; }
	unsigned long long get_Highscore() const { return this->High_Score; }
};