#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

class Player
{
private:
	int delay;
	Texture playerTex;
	Texture backTex;
	Sprite player;

public:
	Player();
	~Player();
};

