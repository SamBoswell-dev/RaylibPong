#pragma once

#include "raylib.h"

class Reflector {
public:
	Vector2 position;
private:
	const int offset;
	const int width;
	const int speed;
	const int height;
public:
	Reflector(const int side); // if position is -1, it is the left. if position is 1, it is the right
	void Draw();
	void MoveUp();
	void MoveDown();
	int IsOutOfBounds();
	Rectangle GetCollider();
private:

};