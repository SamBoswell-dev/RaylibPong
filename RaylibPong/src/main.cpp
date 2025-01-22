#include <iostream>
#include "raylib.h"
#include "Game.h"

int main()
{
	Color backgroundColor = { 100, 240, 245, 255 };
	Color leftColor = { 132, 241, 245, 255 };
	Color middleColor = { 176, 242, 245, 150 };

	InitWindow(1100, 700, "My Template");
	InitAudioDevice();
	SetTargetFPS(60);

	Game game = Game();

	while (!WindowShouldClose())
	{
		game.CheckKeyPressed();

		BeginDrawing();
		ClearBackground(backgroundColor);
		DrawRectangle(0, 0, 550, 700, leftColor);
		DrawCircle(550, 350, 100, middleColor);
		game.Draw();

		EndDrawing();
	}
	CloseWindow();
}