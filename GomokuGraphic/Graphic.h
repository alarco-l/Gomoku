#pragma once

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
	void									draw();
	void									loadTexture();

private:

	struct									Player
	{
		sf::Sprite							sprite;
		int									posX;
		int									posY;
	};

	sf::RenderWindow						&_window;
	std::map<std::string, sf::Sprite*>		_sprite;
	std::map<std::string, sf::Texture*>		_texture;
	std::vector<Player>						_player1;
	std::vector<Player>						_player2;
};