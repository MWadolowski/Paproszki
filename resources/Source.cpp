#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <time.h>
#include "WashingMachine.h"
#include "State.h"
#include <SFML\Graphics\Color.hpp>

using namespace sf;
using namespace std;
//////////

int main()
{
	State *all = new State();
	RenderWindow window(VideoMode(WIDTH, HEIGHT), "Pralka invaders 2: Revenge of Pralka");
	Clock stoper;
	srand(time(NULL));
	int vertical;
	int horizontal;
	while (window.isOpen())
	{
		stoper.restart();
		vertical = 0;
		horizontal = 0;
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
				window.close();			
		}
		if (Keyboard::isKeyPressed(Keyboard::Left) && all->getPlayerPosition().x > 30)
			horizontal -= 1;
		if (Keyboard::isKeyPressed(Keyboard::Right) && all->getPlayerPosition().x < WIDTH - 30)
			horizontal += 1;
		if (Keyboard::isKeyPressed(Keyboard::Up) && all->getPlayerPosition().y >= HEIGHT - 50 - 100 + 30)
			vertical -= 1;
		if (Keyboard::isKeyPressed(Keyboard::Down) && all->getPlayerPosition().y <= HEIGHT - 30)
			vertical += 1;
		if (Keyboard::isKeyPressed(Keyboard::Space))
			;//pociski
		all->setPlayerPosition(horizontal, vertical);
		all->changeState();
		all->draw(&window);
		while (stoper.getElapsedTime().asMilliseconds() < 3.f);
	}
	return 0;
}