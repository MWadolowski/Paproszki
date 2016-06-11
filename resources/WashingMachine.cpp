#include "WashingMachine.h"
#include "State.h"
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

WashingMachine::WashingMachine(const Texture &tex)
{

	//Texture *texy = new Texture(tex);
	_sprite.setTexture(tex);
	dead = false;
	_sprite.setScale(0.02, 0.02);
}


WashingMachine::~WashingMachine()
{
	
}

WashingMachine::WashingMachine(int x, const Texture &tex) : WashingMachine(tex)
{
	_sprite.setPosition(x, 0);
}

void WashingMachine::move(int vectorY)
{
	_sprite.move(0, vectorY);
	if (_sprite.getPosition().y > HEIGHT)
		dead = true;
}

bool WashingMachine::operator==(const WashingMachine &other)
{
	if (this == &other)
		return true;
	return false;
}

Sprite WashingMachine::getSprite()
{
	return _sprite;
}

bool WashingMachine::isMachineDead()
{
	return dead;
}

void WashingMachine::killMachine()
{
	dead = true;
}