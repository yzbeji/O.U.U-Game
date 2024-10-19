#include "Pickup_Zapper.h"

Pickup_Zapper::Pickup_Zapper(int X, int Y) : Pickup("C:\\Users\\Stefan\\Desktop\\Pickup - Zapper.png", X, Y) { }
Pickup_Zapper::~Pickup_Zapper() { }
void Pickup_Zapper::Draw()
{
	if (current_Frame % 4 == 0 and current_Frame != 0)
		current_Sprite++;
	if (current_Frame == 60)
		current_Frame = current_Sprite = 0;
	const Vector2 Origin = { 0, 0 };
	const Rectangle Source = { current_Sprite * 32, 32, 32, 32 };
	const Rectangle Destination = { X, Y, 45, 45 };
	DrawTexturePro(Item, Source, Destination, Origin, 0.f, RAYWHITE);
	current_Frame++;
	this->Y += 3;
}
std::string Pickup_Zapper::Pickup_Type() { return "Zapper"; }
