#include "raylib.h"
#include "Game.h"
#include "Icon.h"
void Countdown(double&& Time, const Font& Countdown_Font)
{	
	if (Time >= 4.5) 
	{
		if (Time <= 5.5)
			DrawTextEx(Countdown_Font, "3", { 365, 300 }, 90, 0, WHITE);
		else if (Time <= 7)
			DrawTextEx(Countdown_Font, "2", { 365, 300 }, 90, 0, WHITE);
		else if (Time <= 8.5)
			DrawTextEx(Countdown_Font, "1", { 365, 300 }, 90, 0, WHITE);
		else if (Time <= 10.5)
			DrawTextEx(Countdown_Font, "GO!", { 285, 300 }, 90, 0, WHITE);
	}
}
void End(const Font& Pixel_Font, unsigned long long Score) 
{ 
	std::string display_Score = "SCORE: " + std::to_string(Score);
	DrawTextEx(Pixel_Font, display_Score.c_str(), {(float) 500 - 30 * display_Score.size(), 360}, 30, 0, WHITE);
	DrawTextEx(Pixel_Font, "YOU LOST :(", { (float) 500 - 30 * display_Score.size(), 300 }, 30, 0, WHITE);
}

int main(void) {

	InitWindow(800, 800, "OMEGA's Unknown Universe");
	InitAudioDevice();
	SetTargetFPS(60);
	Sound Theme_Song = LoadSound("C:\\Users\\Stefan\\Desktop\\Theme Song.wav");
	Font Pixel_Font = LoadFont("C:\\Users\\Stefan\\Desktop\\Countdown Font.ttf");
	Icon I;
	Game OUU;
	PlaySound(Theme_Song);
	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(BLACK);
		if (OUU.get_Finished() == false)
		{
			OUU.HandleInput();
			if (GetTime() <= 10.5)
				Countdown(GetTime(), Pixel_Font);
		}
		else
			End(Pixel_Font, OUU.get_Highscore());
		EndDrawing();	
	}
	UnloadSound(Theme_Song);
	CloseAudioDevice();
	CloseWindow();
	return 0;
}