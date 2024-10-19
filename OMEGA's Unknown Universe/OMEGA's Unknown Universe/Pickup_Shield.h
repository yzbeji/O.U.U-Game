#pragma once
#include "Pickup.h"

class Pickup_Shield : public Pickup
{
	public:
		Pickup_Shield(int, int);
		~Pickup_Shield();
		void Draw() override;
		std::string Pickup_Type() override;
};