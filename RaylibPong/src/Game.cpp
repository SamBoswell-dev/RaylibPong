#include "Game.h"
#include "raylib.h"

Game::Game() : left(-1), right(1)
{
	
}

void Game::CheckKeyPressed()
{
	if (IsKeyDown(KEY_UP))
	{
		right.MoveUp();
	}
	else if (IsKeyDown(KEY_DOWN))
	{
		right.MoveDown();
	}

	if (IsKeyDown(KEY_W))
	{
		left.MoveUp();
	}
	else if (IsKeyDown(KEY_S))
	{
		left.MoveDown();
	}
}

void Game::Draw() const
{
	left.Draw();
	right.Draw();
}
