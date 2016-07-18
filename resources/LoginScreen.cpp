#include "LoginScreen.h"



LoginScreen::LoginScreen()
{
	startTexture.loadFromFile("forest.jpg");

	startBackground.setTexture(startTexture);
	startBackground.scale(0.45, 0.45);

	textboxIP.setPosition(280, 250);
	textboxIP.setFillColor(Color::White);
	textboxIP.setSize(Vector2f(220, 30));

	textboxNick.setPosition(280, 300);
	textboxNick.setFillColor(Color::White);
	textboxNick.setSize(Vector2f(100, 30));

	font.loadFromFile("georgia.ttf");
	tekscik.setFont(font);
	tekscik.setString("Podaj IP klienta/serwera i nick i nacisnij enter");
	tekscik.setPosition(280, 210);
	tekscik.setCharacterSize(20);
	tekscik.setColor(Color::Green);

	text_ip.setFont(font);
	text_ip.setPosition(280, 247);
	text_ip.setCharacterSize(20);
	text_ip.setColor(Color::Green);
	text_ip.setString("127.0.0.1");

	text_nick.setFont(font);
	text_nick.setPosition(282, 297);
	text_nick.setCharacterSize(20);
	text_nick.setColor(Color::Green);
}


LoginScreen::~LoginScreen()
{
}

void LoginScreen::run(RenderWindow *window)
{
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			if (event.key.code == Keyboard::Return)
				return;
			if (event.key.code == Keyboard::Tab && event.type == Event::KeyReleased)
			{
				switch (chosen)
				{
				case IP:
					chosen = nick;
					string = text_nick.getString();
					break;
				case nick:
					chosen = IP;
					string = text_ip.getString();
					break;
				default:
					break;
				}
			}
			else if (event.key.code == Keyboard::BackSpace && event.type == Event::KeyReleased)
			{
				if (string.getSize() > 0)
				{
					string.erase(string.getSize() - 1);
					setString();
				}
			}
			else if (event.type == Event::TextEntered &&
				!Keyboard::isKeyPressed(Keyboard::Tab) &&
				!Keyboard::isKeyPressed(Keyboard::Return) &&
				!Keyboard::isKeyPressed(Keyboard::BackSpace))
			{
				if (event.text.unicode < 128)
					string += (char)event.text.unicode;
				setString();
			}
			else if (event.type == Event::Closed)
				window->close();
			else if (Keyboard::isKeyPressed(Keyboard::Escape))
				window->close();
		}
		window->clear();
		window->draw(startBackground);
		window->draw(textboxIP);
		window->draw(textboxNick);
		window->draw(tekscik);
		window->draw(text_ip);
		window->draw(text_nick);
		window->display();
	}
}

String LoginScreen::getIP()
{
	return text_ip.getString();
}

String LoginScreen::getNick()
{
	return text_nick.getString();
}

void LoginScreen::setString()
{
	if (chosen == IP)
		text_ip.setString(string);
	else if (chosen == nick)
		text_nick.setString(string);
}
