#include "Bullet_Auto-Cannon.h"

Bullet_AutoCannon::Bullet_AutoCannon(int X, int Y) : Bullet(LoadTexture("C:\\Users\\Stefan\\Desktop\\Bullet - Auto - Cannon.png")), X(X), Y(Y), current_Frame(0), current_Sprite(0), Fired(false) { }
Bullet_AutoCannon::~Bullet_AutoCannon()
{
	UnloadTexture(Bullet);
}
void Bullet_AutoCannon::Draw()
{
	const Vector2 Origin = { 0, 0 };
	if (current_Frame == 60)
		current_Frame = 0;
	Rectangle Source = { current_Sprite * 32, 32, 32, 32 };
	Rectangle Destination = { this->X, this->Y, 45, 46 };
	DrawTexturePro(Bullet, Source, Destination, Origin, 0.f, RAYWHITE);
	if (current_Frame % 5 == 0 and current_Frame)
		current_Sprite++;
	if (current_Sprite == 4)
		current_Sprite = 0;
	current_Frame++;
	this->Y -= 5;

}
int Bullet_AutoCannon::get_Y() const { return this->Y; }
int Bullet_AutoCannon::get_X() const { return this->X; }