#include "Pickup.h"

Pickup::Pickup(const char* Item_PNG, const int X, const int Y) : Item(LoadTexture(Item_PNG)), X(X), Y(Y), current_Frame(0), current_Sprite(0), Timer(0), Picked_UP(false) {}
Pickup::~Pickup()
{
	UnloadTexture(Item);
}
