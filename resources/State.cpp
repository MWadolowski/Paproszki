#include "State.h"
#include "WashingMachine.h"
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
	playerTex.loadFromFile("destroyer.png");
	pralka.loadFromFile("pralka.jpg");
	for (int i = 0; i < 2;i++)
	{
		otherPlayers[i].setTexture(playerTex);
		otherPlayers[i].setPosition(400, 450);
		otherPlayers[i].setScale(0.2, 0.2);
	}
	player.setTexture(playerTex);
	player.setOrigin(player.getGlobalBounds().width/2, player.getGlobalBounds().height/2);
	player.setPosition(400, HEIGHT - player.getGlobalBounds().height/2 + 100);
	
	player.rotate(180);
	player.setScale(0.2, 0.2);
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

vector<WashingMachine*>* State::getCollection()
{
	return &contener;
}

void State::draw(RenderWindow *window)
{
	window->clear(Color::Blue);
	window->draw(background);
	window->draw(player);
	for (auto &element : contener)
		window->draw(element->_sprite);//taki foreach w cpp dla vectora
	window->display();
}

void State::addMachines(int nMachines)
{
	for (int i = 0; i < nMachines; i++)
	{
		WashingMachine *one = new WashingMachine(rand() % WIDTH, pralka);
		contener.push_back(one);
	}
}

void State::changeState()
{
	if (machineTimer >= MACHINETIMER)
	{
		addMachines(NEWMACHINESNUMBER);
		machineTimer = 0;
	}
	if (machineDelay >= MACHINEDELAY)
	{
		for (auto &element : contener)
			element->move(1);
		machineDelay = 0;
	}
	//for (int i = 0; i < contener.size(); i++)
	//{
	//	if (contener[i]->_sprite.getPosition().y >= HEIGHT)
	//	{
	//		swap(contener[i], contener[contener.size() - 1]);
	//		contener.pop_back();
	//	}
	//}
	humanDelay++;
	machineDelay++;
	machineTimer++;
}
