#pragma once
#include "Collision.h"
bool Explode(Spaceship& Rocket, Asteroid*& Rock, Shield* Protection)
{
	const Rectangle Rocket_Parameters = { Rocket.get_X() + 18, Rocket.get_Y(), 60, 24 };
	const Rectangle Rock_Parameters = { Rock->get_X() + 25, Rock->get_Y(), 35, 35 };
	if (CheckCollisionRecs(Rocket_Parameters, Rock_Parameters) and Rock->get_Destroyed() == false)
		if (Protection == nullptr)
			Rocket.set_HP();
	return CheckCollisionRecs(Rocket_Parameters, Rock_Parameters);
}
bool Bullseye(Bullet_AutoCannon*& Bullet, Asteroid*& Rock)	
{
	const Rectangle Rock_Parameters = { Rock->get_X() + 25, Rock->get_Y(), 35, 35 };
	const Rectangle Bullet_Parameters = { Bullet->get_X() + 10, Bullet->get_Y() + 5, 12, 12 };
	return CheckCollisionRecs(Rock_Parameters, Bullet_Parameters);
}
bool Bullseye(Bullet_Zapper*& Zap, Asteroid*& Rock, int Spaceship_X)
{
	const Rectangle Rock_Parameters = { Rock->get_X() + 25, Rock->get_Y(), 35, 35 };
	const Rectangle Zap_Parameters = { Spaceship_X + 26, Zap->get_Y(), 12, 60};
	return CheckCollisionRecs(Rock_Parameters, Zap_Parameters);
}
bool Activate(Spaceship& Rocket, Pickup* Item) 
{
	const Rectangle Rocket_Parameters = { Rocket.get_X() + 18, Rocket.get_Y(), 60, 24 };
	const Rectangle Item_Parameters = { Item->get_X() + 6, Item->get_Y(), 40, 40 };
	return CheckCollisionRecs(Rocket_Parameters, Item_Parameters);
}