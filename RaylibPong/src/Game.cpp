#include "Game.h"
#include "raylib.h"

Game::Game() : left(-1), right(1), ball(this)
{
	
}

void Game::CheckKeyPressed()
{
	if (IsKeyDown(KEY_UP))
	{
		if (right.IsOutOfBounds() != 1)
			right.MoveUp();
	}
	else if (IsKeyDown(KEY_DOWN))
	{
		if (right.IsOutOfBounds() != -1)
			right.MoveDown();
	}

	if (IsKeyDown(KEY_W))
	{
		if (left.IsOutOfBounds() != 1)
			left.MoveUp();
	}
	else if (IsKeyDown(KEY_S))
	{
		if (left.IsOutOfBounds() != -1)
			left.MoveDown();
	}

	if (IsKeyPressed(KEY_T))
		SpawnBall();
}

void Game::Draw()
{
	left.Draw();
	right.Draw();
	ball.Draw();
}

void Game::SpawnBall()
{
	ball = Ball(this);
}