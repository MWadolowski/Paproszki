#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;
using namespace std;
class WashingMachine
{
public:
	Image _texture;
	Sprite _sprite;
	WashingMachine(const Texture &tex);
	~WashingMachine();
	WashingMachine(int x, const Texture &tex);
	void move(int vectorY);
	bool operator==(const WashingMachine &other);
};

