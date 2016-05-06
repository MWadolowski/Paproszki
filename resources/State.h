#pragma once
#include <SFML\Graphics.hpp>
#include "WashingMachine.h"
#include "constans.h"
using namespace sf;
using namespace std;

class State
{
private:
	int humanDelay;
	int machineDelay;
	int machineTimer;
	Sprite background;
	Texture pralka;
	Texture playerTex;
	Texture backTex;
	Sprite player;
	Sprite *otherPlayers = new Sprite[2];
	vector<WashingMachine*> contener;

public:
	State();
	~State();
	Vector2f getPlayerPosition();
	void setPlayerPosition(int x, int y);
	Vector2f getEnemyPosition(int index);
	void setEnemyPosition(int index, int x);
	vector<WashingMachine*>* getCollection();
	void draw(RenderWindow *window);
	void addMachines(int nMachines);
	void changeState();
};

