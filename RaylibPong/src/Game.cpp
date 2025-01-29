#include "Game.h"
#include "raylib.h"
#include <iostream>

#define CHEATS


Game::Game() : left(-1), right(1), ball(this), showHitboxes(false)
{
	background = LoadTexture("textures\\Background_Grid.png");
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

bool Game::CheckCollisions(int side) // side -1 is left, side 1 is right
{
	switch (side)
	{
	case -1:
		if (CheckCollisionRecs(left.GetCollider(), ball.GetCollider()))
			return true;
		else
			return false;
		break;
	case 1:
		if (CheckCollisionRecs(right.GetCollider(), ball.GetCollider()))
			return true;
		else
			return false;
		break;
	default:
		std::cout << "Error: CheckCollision arguments need to be either -1 or 1" << std::endl;
		break;
	}
}

void Game::Draw()
{
#ifdef CHEATS
	if (showHitboxes)
	{
		left.showHitboxes = true;
		right.showHitboxes = true;
		ball.showHitboxes = true;
	}
	else
	{
		left.showHitboxes = false;
		right.showHitboxes = false;
		ball.showHitboxes = false;
	}
#endif

	DrawTexture(background, 0, 0, WHITE);
	left.Draw();
	right.Draw();
	ball.Draw();
}

void Game::SpawnBall()
{
	ball = Ball(this);
}

Ball Game::GetBall() { return ball; }