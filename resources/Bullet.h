#pragma once
#include <SFML\Graphics.hpp>
#include "WashingMachine.h"
using namespace sf;

class Bullet
{
public:
	Bullet( int x, int y, CircleShape &bulletShape);
	~Bullet();
	void move(int y);
	void collide(WashingMachine *enemy);
	bool isBulletDead();
	void destroyBullet();
	CircleShape getShape();
	
private:
	CircleShape bullet;
	const int bulletSize = 5;
	int direction;
	bool boom;
	bool dead;
};

