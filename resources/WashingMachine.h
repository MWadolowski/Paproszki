#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;
class WashingMachine
{
public:
	WashingMachine(const Texture &tex);
	~WashingMachine();
	WashingMachine(int x, const Texture &tex);
	void move(int vectorY);
	bool operator==(const WashingMachine &other);
	Sprite getSprite();
	bool isMachineDead();
	void killMachine();

private: 
	Image _texture;
	Sprite _sprite;
	bool dead;
};

