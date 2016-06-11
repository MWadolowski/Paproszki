#pragma once
#include <SFML\Graphics.hpp>
#include "WashingMachine.h"
#include "Bullet.h"
#include "constans.h"
using namespace sf;
using namespace std;

class State
{

private:
	int humanDelay;
	int machineDelay;
	int machineTimer;
	int bulletDelay;
	int bulletTimer = 51;
	CircleShape naboj;
	Sprite background;
	Texture pralka;
	Texture playerTex;
	Texture backTex;
	Sprite player;
	Sprite *otherPlayers = new Sprite[2];
	vector<Bullet*> bulletContener;
	vector<WashingMachine*> machineContener;

public:
	State();
	~State();
	Vector2f getPlayerPosition();
	void setPlayerPosition(int x, int y);
	Vector2f getEnemyPosition(int index);
	void setEnemyPosition(int index, int x);
	vector<Bullet*> getBulletCollection();
	vector<WashingMachine*> getCollection();
	void draw(RenderWindow *window);
	void addMachines(int nMachines);
	void addBullets(int bulletNumber);
	void changeState();
	void playerShoot();
	void bulletsAreMoving(RenderWindow *_window, State *state);
	void updateObjects();
};

