#include <iostream>
#include "raylib.h"
#include "Game.h"

#include "imgui.h"
#include "rlImGui.h"

#define CHEATS

int main()
{
	Color backgroundColor = { 100, 240, 245, 255 };
	Color leftColor = { 132, 241, 245, 255 };
	Color middleColor = { 176, 242, 245, 150 };

	InitWindow(1300, 733, "My Template");
	InitAudioDevice();
	SetTargetFPS(60);

	Game game = Game();

#ifdef CHEATS
	rlImGuiSetup(true);
#endif


	while (!WindowShouldClose())
	{
		game.CheckKeyPressed();

		BeginDrawing();
		ClearBackground(backgroundColor);
		game.Draw();

#ifdef CHEATS
		rlImGuiBegin();

		ImGui::SliderFloat("Ball Speed", &game.ball.speedMultiplier, 0, 5);
		ImGui::Checkbox("Show Hitboxes", &game.showHitboxes);

		rlImGuiEnd();
#endif

		EndDrawing();
	}

	rlImGuiEnd();

	CloseWindow();
}