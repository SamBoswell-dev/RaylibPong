#include "Ball.h"
#include "Game.h"


Ball::Ball(Game* game) : isMovingRight(true), isMovingDown(true), radius(10), horizontalSpeed(6), verticalSpeed(4.88), game(game)
{
	sprite = LoadTexture("textures\\Ball.png");
	position.x = (GetScreenWidth() / 2) + 44.79;
	position.y = (GetScreenHeight() / 2) - 12.61;
}

Ball::~Ball()
{

}

void Ball::Draw()
{
	Move();
	//DrawCircle(position.x, position.y, radius, DARKGREEN);
	DrawTexture(sprite, position.x - radius, position.y - radius, WHITE);
	DrawRectangleLinesEx(GetCollider(), 1, RED);
	DrawCircle(position.x, position.y, 2.f, RED);
	DrawCircle(position.x + radius, position.y + radius, 2.f, RED);

}

void Ball::Move()
{
	// Check for bounds
	BoundsCheck();
	
	if (isMovingRight)
		position.x += horizontalSpeed;
	else
		position.x -= horizontalSpeed;


	if (isMovingDown)
		position.y += verticalSpeed;
	else
		position.y -= verticalSpeed;

}

void Ball::BoundsCheck()
{
	if (game->CheckCollisions(-1))
	{
		isMovingRight = true;
		verticalSpeed = GetRandomValue(4, 10);
		horizontalSpeed = GetRandomValue(4, 10);
	}

	if (game->CheckCollisions(1))
	{
		isMovingRight = false;
		verticalSpeed = GetRandomValue(4, 10);
		horizontalSpeed = GetRandomValue(4, 10);
	}

	if (position.x + radius >= GetScreenWidth())
		game->SpawnBall();

	if (position.x - radius <= 0)
		game->SpawnBall();

	if (position.y + radius >= GetScreenHeight())
		isMovingDown = false;

	if (position.y - radius <= 0)
		isMovingDown = true;
}

Rectangle Ball::GetCollider()
{
	return { (position.x - radius) + 4, (position.y - radius) + 4, (float)radius * 2, (float)radius * 2 };
}