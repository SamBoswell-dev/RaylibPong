#pragma once
#include "raylib.h"


class Game;

class Ball {
public:
	static float speedMultiplier;
private:
	Vector2 position;
	bool isMovingRight;
	bool isMovingDown;
	int radius;
	int horizontalSpeed;
	int verticalSpeed;
	Texture2D sprite;
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