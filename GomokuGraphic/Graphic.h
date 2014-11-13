#pragma once

#include <iostream>

#include <string>
#include <map>
#include <vector>

#include "SFML/Graphics.hpp"

class										Graphic
{
public:
	Graphic(sf::RenderWindow &);
	~Graphic();

	void									run();

private:

	struct									Player
	{
		sf::Sprite							sprite;
		int									posX;
		int									posY;
	};

private:
	void									draw();
	void									drawMenu();
	void									loadTexture();
	void									putPion(Player &, bool);

private:

	sf::RenderWindow						&_window;
	std::map<std::string, sf::Sprite*>		_sprite;
	std::map<std::string, sf::Texture*>		_texture;
	std::vector<Player>						_player1;
	std::vector<Player>						_player2;
	sf::FloatRect							_jvsj;
	sf::FloatRect							_jvsia;
};