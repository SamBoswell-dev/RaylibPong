#include <iostream>
#include "raylib.h"
#include "Game.h"

#include "imgui.h"
#include "rlImGui.h"

int main()
{
	Color backgroundColor = { 100, 240, 245, 255 };
	Color leftColor = { 132, 241, 245, 255 };
	Color middleColor = { 176, 242, 245, 150 };

	InitWindow(1300, 733, "My Template");
	InitAudioDevice();
	SetTargetFPS(60);

	rlImGuiSetup(true);

	Game game = Game();

	while (!WindowShouldClose())
	{
		game.CheckKeyPressed();

		BeginDrawing();
		ClearBackground(backgroundColor);
		game.Draw();

		rlImGuiBegin();

		ImGui::ShowDemoWindow();

		rlImGuiEnd();


		EndDrawing();
	}

	rlImGuiEnd();

	CloseWindow();
}