#pragma once
#include "raylib.h"
#include "Pickup.h"

class Pickup_Zapper : public Pickup
{
	public:
		Pickup_Zapper(int, int);
		~Pickup_Zapper();
		void Draw() override;
		std::string Pickup_Type() override;
};