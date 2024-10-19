#pragma once
#include <raylib.h>
class Space_Background {
	private:
		const int Background_Height = 3000;
		Texture2D Space;
		const Vector2 Origin{ 0, 0 };
		int current_SpriteY;
		const int Y = -1;
	public:
		Space_Background();
		~Space_Background();
		void Draw(void);
};