#include "Graphic.h"

Graphic::Graphic(sf::RenderWindow &window) : _window(window)
{
	_texture["background"] = new sf::Texture;
	_sprite["background"] = new sf::Sprite;
	_texture["title"] = new sf::Texture;
	_sprite["title"] = new sf::Sprite;
	_texture["plateau"] = new sf::Texture;
	_sprite["plateau"] = new sf::Sprite;
	_texture["blanc"] = new sf::Texture;
	_sprite["blanc"] = new sf::Sprite;
	_texture["noir"] = new sf::Texture;
	_sprite["noir"] = new sf::Sprite;
}

Graphic::~Graphic()
{

}

void					Graphic::run()
{
	bool				player = true;
	Player				p;

	loadTexture();
	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				_window.close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				p.posX = sf::Mouse::getPosition(_window).x;
				p.posY = sf::Mouse::getPosition(_window).y;
				if (player)
				{
					p.sprite = *_sprite["blanc"];
					p.sprite.setPosition(p.posX, p.posY);
					_player1.push_back(p);
				}
				else
				{
					p.sprite = *_sprite["noir"];
					p.sprite.setPosition(p.posX, p.posY);
					_player2.push_back(p);
				}
				player = !player;
			}
		}

		_window.clear();
		draw();
		_window.display();
	}
}

void					Graphic::draw()
{
	_window.draw(*_sprite["background"]);
	_window.draw(*_sprite["title"]);
	_window.draw(*_sprite["plateau"]);
	for (std::vector<Player>::iterator it = _player1.begin(); it != _player1.end(); ++it)
		_window.draw(it->sprite);
	for (std::vector<Player>::iterator it = _player2.begin(); it != _player2.end(); ++it)
		_window.draw(it->sprite);
}

void					Graphic::loadTexture()
{
	if (!_texture["background"]->loadFromFile("../Ressource/background.png"))
		throw std::runtime_error("Failed load texture");
	_sprite["background"]->setTexture(*_texture["background"]);
	if (!_texture["title"]->loadFromFile("../Ressource/title.png"))
		throw std::runtime_error("Failed load texture");
	_sprite["title"]->setTexture(*_texture["title"]);
	if (!_texture["plateau"]->loadFromFile("../Ressource/plateau.png"))
		throw std::runtime_error("Failed load texture");
	_sprite["plateau"]->setTexture(*_texture["plateau"]);
	if (!_texture["blanc"]->loadFromFile("../Ressource/blanc.png"))
		throw std::runtime_error("Failed load texture");
	_sprite["blanc"]->setTexture(*_texture["blanc"]);
	if (!_texture["noir"]->loadFromFile("../Ressource/noir.png"))
		throw std::runtime_error("Failed load texture");
	_sprite["noir"]->setTexture(*_texture["noir"]);
}