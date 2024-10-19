#pragma once
#include "Asteroid.h"
#include "Spaceship.h"
#include "Pickup.h"
#include "Shield.h"
#include "Bullet_Auto-Cannon.h"
#include "Bullet_Zapper.h"
bool Explode(Spaceship&, Asteroid*&, Shield*);
bool Bullseye(Bullet_AutoCannon*&, Asteroid*&);
bool Bullseye(Bullet_Zapper*&, Asteroid*&, int);
bool Activate(Spaceship&, Pickup*);
