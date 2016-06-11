#include "Bullet.h"
#include "WashingMachine.h"
#include <SFML\Graphics.hpp>
#include "State.h"
using namespace sf;

Bullet::Bullet( int x, int y, CircleShape &bulletShape)
{
	bullet = bulletShape;
	bullet.setRadius(bulletSize);
	bullet.setFillColor(Color::White);
	bullet.setOrigin(bulletSize / 2, bulletSize / 2);
	bullet.setPosition(x, y);
	dead = false;
}

Bullet::~Bullet()
{
}

void Bullet::move(int y)
{
	bullet.move(0, -y);
	if (bullet.getPosition().y <= 0)
		dead = true;	
}

void Bullet::collide(WashingMachine *enemy)
{
	int bla = enemy->getSprite().getPosition().y + enemy->getSprite().getGlobalBounds().height;//wysokosc
	int ble = bullet.getPosition().y - bulletSize;
	int bu = bullet.getPosition().x - bulletSize;
	int be = enemy->getSprite().getPosition().x;
	if (bla >= ble &&
		bu >= be &&
		bullet.getPosition().x + bulletSize < enemy->getSprite().getPosition().x + enemy->getSprite().getGlobalBounds().width)
		/*if (enemy->_sprite.getPosition().y + enemy->_sprite.getGlobalBounds().height/2 <= this->bullet.getPosition().y - BulletSize / 2 &&
			this->bullet.getPosition().x + BulletSize / 2 > enemy->_sprite.getPosition().x - enemy->_sprite.getGlobalBounds().width/2 &&
			this->bullet.getPosition().x - BulletSize / 2 < enemy->_sprite.getPosition().x + enemy->_sprite.getGlobalBounds().width/2)*/
	//if(chuj->bullet.getPosition().y - BulletSize/2 <200)
	{
		dead = true;
		enemy->killMachine();	
	}
}

bool Bullet::isBulletDead()
{
	return dead;
}

void Bullet::destroyBullet()
{
	dead = true;
}

CircleShape Bullet::getShape()
{
	return bullet;
}