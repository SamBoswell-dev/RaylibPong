#pragma once
#include "Reflector.h"
#include "Ball.h"

class Game {
public:
	Reflector left;
	Reflector right;
	Ball ball;
private:
	Texture2D background;
public:
	Game();
	void CheckKeyPressed();
	bool CheckCollisions(int side);
	void Draw();
	void SpawnBall();
	Ball GetBall();
private:

};