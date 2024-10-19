#include "Game.h"
#include <string>
#include <cstdlib>
#include <cmath>
Game::Game() : Timer(GetTime()), High_Score(0), Theme_Font(LoadFont("C:\\Users\\Stefan\\Desktop\\Countdown Font.ttf")), Finished(false)
{
	Auto_Cannon = new AutoCannon(Rocket.get_X(), Rocket.get_Y());
}
void Game::HandleInput()
{
	if (Rocket.get_HP() == 0)
		this->Finished = true;
    Background.Draw();
    Rocket.Draw();
	if (Auto_Cannon != nullptr)
		Auto_Cannon->Draw(Rocket.get_X(), Rocket.get_Y());		
	if (Zap != nullptr)	
	{
		Zap->Draw(Rocket.get_X(), Rocket.get_Y());	
		if (GetTime() - Zap->get_Timer() >= 10)	
		{
			delete Zap;
			Zap = nullptr;
			Auto_Cannon = new AutoCannon(Rocket.get_X(), Rocket.get_Y());			
		}
	}
	if (GetTime() >= 10.5)
	{
		std::string display_Score = "SCORE: " + std::to_string(High_Score);
		DrawTextEx(Theme_Font, display_Score.c_str(), { (float)800 - 15 * (display_Score.size()) - 10, 10 }, 15, 0, RAYWHITE);
		for (std::vector < Asteroid* >::iterator Rock = Asteroids.begin(); Rock != Asteroids.end();)
		{
			if(Auto_Cannon != nullptr)
				Auto_Cannon->Checker((*Rock));
			if (Zap != nullptr)
				Zap->Checker((*Rock), Rocket.get_X());
			if ((*Rock)->get_Y() > 800)
			{
				delete (*Rock);
				Rock = Asteroids.erase(Rock);
			}
			else
			{
				if ((*Rock)->get_Destroyed() == false and Explode(Rocket, (*Rock), Protection) == false)
					(*Rock)->Fall(), Rock++;
				else
				{
					(*Rock)->Boom();
					if (GetTime() - (*Rock)->get_Timer() > 0.35)
					{
						unsigned short Chance = rand() % 3;
						if (Chance == 0)
							Pickups.push_back(new Pickup_Shield((*Rock)->get_X() + 24, (*Rock)->get_Y()));
						else if (Chance == 1)
							Pickups.push_back(new Pickup_Zapper((*Rock)->get_X() + 24, (*Rock)->get_Y()));
						High_Score += 5;
						delete (*Rock);
						Rock = Asteroids.erase(Rock);
					}
					else
						Rock++;
				}
			}	
		}
		for (std::vector < Pickup* >::iterator Item = Pickups.begin(); Item != Pickups.end();)
		{
			std::vector < Pickup* >::iterator& it = Item;
			if ((*it)->get_Y() > 800)
			{
				delete (*it);
				it = Pickups.erase(it);
			}
			else
			{
				(*it)->Draw();
				if (Activate(Rocket, (*it)) == true)
				{
					if (Protection == nullptr and (*it)->Pickup_Type() == "Shield")
						Protection = new Shield(Rocket.get_X(), Rocket.get_Y());
					else if (Zap == nullptr and (*it)->Pickup_Type() == "Zapper")
					{
						if (Auto_Cannon != nullptr)
						{
							delete Auto_Cannon;
							Auto_Cannon = nullptr;
						}
						Zap = new Zapper(Rocket.get_X(), Rocket.get_Y());
					}
					delete (*it);
					it = Pickups.erase(it);
				}
				else
					it++;
			}
		}
		if (Protection != nullptr)	
		{	
			Protection->Draw(Rocket.get_X(), Rocket.get_Y());	
			if (GetTime() - Protection->get_Timer() > 3)	
			{
				delete Protection;
				Protection = nullptr;
			}
		}	
		if (abs(GetTime() - Timer) > 2)
		{
			Timer = GetTime();
			std::random_device random;	
			std::mt19937 gen(random());	
			std::uniform_int_distribution < int > first_distribution(0, 710);	
			std::uniform_int_distribution < int > second_distribution(-270, -90);	
			Asteroids.push_back(new Asteroid(first_distribution(gen), second_distribution(gen)));
		}
	}
}

Game::~Game()
{
	UnloadFont(Theme_Font);
	Asteroids.clear();
}

