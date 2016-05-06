#include "WashingMachine.h"
#include "State.h"
#include <SFML\Graphics.hpp>
using namespace sf;
using namespace std;

WashingMachine::WashingMachine(const Texture &tex)
{

	//Texture *texy = new Texture(tex);
	_sprite.setTexture(tex);

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
}

bool WashingMachine::operator==(const WashingMachine &other)
{
	//if (this->_sprite.getPosition().x != other._sprite.getPosition().x)
	//	return false;
	//if (this->_sprite.getPosition().y != other._sprite.getPosition().y)
	//	return false;
	//return true;
	if (this == &other)
		return true;
	return false;
}