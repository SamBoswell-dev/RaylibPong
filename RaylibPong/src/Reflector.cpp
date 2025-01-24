#include "Reflector.h"

Reflector::Reflector(int side) : offset(20), width(15), speed(8), height(100)
{

	if (side == -1)
	{
		position.x = 0 + offset;
	}
	else
	{
		position.x = GetScreenWidth() - (offset + width);
	}
		position.y = (GetScreenHeight() / 2) - 50;
}

void Reflector::Draw()
{
	DrawRectangleRounded({position.x, position.y, (float)width, (float)height}, .7f, 5, BLACK);
}

void Reflector::MoveUp()
{
	position.y -= speed;
}

void Reflector::MoveDown()
{
	position.y += speed;
}

int Reflector::IsOutOfBounds() // Returns 0 if not out of bounds. Returns 1 if above bounds, and -1 if below bounds
{
	if (position.y <= 0)
		return 1;
	if (position.y >= GetScreenHeight() - height)
		return -1;

	return 0;
}

Rectangle Reflector::GetCollider()
{
	return Rectangle{ position.x, position.y, (float)width, (float)height };
}