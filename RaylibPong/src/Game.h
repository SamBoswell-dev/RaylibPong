#pragma once
#include "Reflector.h"

class Game {
public:
	Reflector left;
	Reflector right;
private:

public:
	Game();
	void CheckKeyPressed();
	void Draw() const;
private:

};