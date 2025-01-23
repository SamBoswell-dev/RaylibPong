#pragma once
#include "raylib.h"


class Game;

class Ball {
public:

private:
	Vector2 position;
	bool isMovingRight;
	bool isMovingDown;
	int radius;
	int horizontalSpeed;
	int verticalSpeed;
public:
	Game* game;
	Ball(Game* game);
	~Ball();
	void Draw();
	void Move();
	Rectangle GetCollider();
private:
	void BoundsCheck();
};