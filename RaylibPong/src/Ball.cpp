#include "Ball.h"
#include "Game.h"


Ball::Ball(Game* game) : isMovingRight(true), isMovingDown(true), radius(15), horizontalSpeed(6), verticalSpeed(4.88), game(game)
{
	position.x = GetScreenWidth() / 2;
	position.y = GetScreenHeight() / 2;
}

Ball::~Ball()
{

}

void Ball::Draw()
{
	Move();
	DrawCircle(position.x, position.y, radius, DARKGREEN);
	DrawRectangleLinesEx(GetCollider(), 3, WHITE);
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
	// TODO: if ball collision collides with reflector collision, set moving vars, 
	// else if position goes out of bounds call spawn ball in game.cpp

	if (CheckCollisionRecs(GetCollider(), )

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
	return { position.x - radius, position.y - radius, (float)radius * 2, (float)radius * 2 };
}