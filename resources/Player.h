#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Bullet.h"

using namespace sf;

class Player
{
private:
	int delay;
	Texture playerTex;
	Texture backTex;
	Sprite player;
	vector<Bullet> playersBullets;

public:
	Player();
	~Player();
};

