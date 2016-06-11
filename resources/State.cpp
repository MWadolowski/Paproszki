#include "State.h"
#include "WashingMachine.h"
#include "Bullet.h"
#include <algorithm>
#include <iterator>
#include <iostream>
using namespace sf;
using namespace std;

State::State()
{
	backTex.loadFromFile("background.png");
	backTex.setRepeated(true);
	background.setTexture(backTex);
	background.setTextureRect(IntRect(0, 0, 800, 500));
	//playerTex.loadFromFile("samolot.png");
	playerTex.loadFromFile("destroyer.png");
	pralka.loadFromFile("pralka.jpg");
	for (int i = 0; i < 2;i++)
	{
		otherPlayers[i].setTexture(playerTex);
		otherPlayers[i].setPosition(400, 450);
		otherPlayers[i].setScale(0.2, 0.2);
	}
	player.setTexture(playerTex);

	player.setOrigin(player.getGlobalBounds().width / 2, player.getGlobalBounds().height / 2);
	player.setPosition(400, HEIGHT - player.getGlobalBounds().height / 2 + 100);
	player.rotate(180);
	player.setScale(0.2, 0.2);
	//
	humanDelay = 0;
	machineDelay = 0;
	machineTimer = 0;
}


State::~State()
{
	
}

Vector2f State::getPlayerPosition()
{
	return player.getPosition();
}

void State::setPlayerPosition(int x, int y)
{
	if (humanDelay >= HUMANDELAY)
	{
		player.move(x, y);
		humanDelay = 0;
	}
}

Vector2f State::getEnemyPosition(int index)
{
	return otherPlayers[index].getPosition();
}

void State::setEnemyPosition(int index, int x)
{
	otherPlayers[index].move(x, 0);
}

vector<WashingMachine*> State::getCollection()
{
	return machineContener;
}

vector<Bullet*> State::getBulletCollection()
{
	return bulletContener;
}

void State::draw(RenderWindow *window)
{
	window->clear(Color::Blue);
	window->draw(background);
	window->draw(player);
	for (auto &machine : machineContener)
	{
		if (machine->isMachineDead() == false)
			window->draw(machine->getSprite());//taki foreach w cpp dla vectora
	}
	for (auto &bullet : bulletContener)
	{
		if(bullet->isBulletDead() == false)
			window->draw(bullet->getShape());
	}
	//taki foreach w cpp dla vectora
	window->display();
}

void State::addMachines(int nMachines)
{
	for (int i = 0; i < nMachines; i++)
	{
		WashingMachine *one = new WashingMachine(rand() % WIDTH, pralka);
		machineContener.push_back(one);
	}
}

void State::addBullets(int bulletNumber)
{
	for (int i = 0; i < bulletNumber; i++)
	{
		Bullet *single = new Bullet(player.getPosition().x, player.getPosition().y, naboj);
		bulletContener.push_back(single);
	}
}


void State::bulletsAreMoving(RenderWindow *_window, State *state)
{	
	int size = bulletContener.size();
	for (int i = 0; i < size; i++)
	{
		if (bulletContener[i]->isBulletDead() == false)
		{
 			bulletContener[i]->move(1);
			for (auto &machine : machineContener)
			{
				if (machine->isMachineDead() == false)
					bulletContener[i]->collide(machine);
			}	
		}
	}
}

void State::playerShoot()
{
	
	if (bulletTimer >= BULLET_TIMER)
	{
		addBullets(NEW_BULLET_NUMBER);
		bulletTimer = 0;
	}
	bulletTimer++;
	bulletDelay++;
}

void State::changeState()
{
	if (machineTimer >= MACHINETIMER )
	{
		addMachines(NEWMACHINESNUMBER);
		machineTimer = 0;
	}
	if (machineDelay >= MACHINEDELAY)
	{
		for (auto &machine : machineContener)
		{
			if(machine->isMachineDead() == false)
				machine->move(1);
		}
		machineDelay = 0;
	}
	humanDelay++;
	machineDelay++;
	machineTimer++;
}

void State::updateObjects()
{
	int size = machineContener.size();
	for (int i = 0; i < size; i++)
	{
		if (machineContener[i]->isMachineDead() == true)
		{
			machineContener.erase(machineContener.begin() + i);
			size = machineContener.size();
		}
	}
	size = bulletContener.size();
	for (int i = 0; i < size; i++)
	{
		if (bulletContener[i]->isBulletDead() == true)
		{
			bulletContener.erase(bulletContener.begin() + i);
			size = bulletContener.size();
		}
	}
}