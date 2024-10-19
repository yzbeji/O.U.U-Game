#include "Spaceship.h"
#include <string>

Spaceship::Spaceship() : current_X(375), HP(100) {
	current_State.push_back(LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Full Health.png"));
	current_State.push_back(LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Slight damage.png"));
	current_State.push_back(LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Damaged.png"));
	current_State.push_back(LoadTexture("C:\\Users\\Stefan\\Desktop\\Spaceship - Very damaged.png"));
	current_SpaceshipSprite = current_State[0];
}
Spaceship::~Spaceship() {
	UnloadTexture(current_SpaceshipSprite);
	current_State.clear();
}
void Spaceship::Draw(void)
{
	std::string display_HP = "HP: " + std::to_string(HP);
	if (HP <= 75 and HP > 50)
		current_SpaceshipSprite = current_State[1];
	else if (HP <= 50 and HP > 25)
		current_SpaceshipSprite = current_State[2];
	else if (HP <= 25 and HP > 0)
		current_SpaceshipSprite = current_State[3];
	if (IsKeyPressed(KEY_ONE))
		Spaceship_Engine.Change_Engine(0);
	else if (IsKeyPressed(KEY_TWO))
		Spaceship_Engine.Change_Engine(1);
	else if (IsKeyPressed(KEY_THREE))
		Spaceship_Engine.Change_Engine(2);
	else if (IsKeyPressed(KEY_FOUR))
		Spaceship_Engine.Change_Engine(3);
	if (IsKeyDown(KEY_LEFT) and IsKeyDown(KEY_RIGHT) == false)
		current_X -= X;
	else if (IsKeyDown(KEY_LEFT) == false and IsKeyDown(KEY_RIGHT) == true)
		current_X += X;
	else;
	current_X = (current_X < 0) ? 0 : current_X;
	current_X = (current_X + 90 > 800) ? 710 : current_X;
	Rectangle Destination{ current_X, current_Y, 90, 90 };
	Spaceship_Engine.Draw(current_X, current_Y);
	DrawTexturePro(current_SpaceshipSprite, Source, Destination, Origin, 0.f, RAYWHITE);
	if(GetTime() >= 10.5)
		DrawTextEx(HP_Font, display_HP.c_str(), { 10, 10 }, 15, 0, RAYWHITE);	
	if (current_Y > 715)
		current_Y -= 1;
}

