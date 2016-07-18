#pragma once
#include <SFML\Graphics.hpp>
#include "chosenUI.h"
using namespace sf;
class LoginScreen
{
public:
	LoginScreen();
	~LoginScreen();
	void run(RenderWindow *window);	
	String getIP();
	String getNick();

private:
	Text tekscik;
	Font font;
	Texture startTexture;
	RectangleShape textboxIP;
	RectangleShape textboxNick;
	Text text_ip;
	Sprite startBackground;
	Text text_nick;
	chosenUI chosen = IP;
	String string = "127.0.0.1";
	void setString();
};

