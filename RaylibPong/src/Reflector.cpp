#include "Reflector.h"

Reflector::Reflector(int side) : offset(20), width(15), speed(5)
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

void Reflector::Draw() const
{
	DrawRectangleRounded({position.x, position.y, (float)width, 100}, .7f, 5, BLACK);
}

void Reflector::MoveUp()
{
	position.y -= speed;
}

void Reflector::MoveDown()
{
	position.y += speed;
}

void Reflector::CheckBounds()
{

}

