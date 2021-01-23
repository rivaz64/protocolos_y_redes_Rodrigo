#pragma once
#include"SFML/Graphics.hpp"
class player:
	public sf::CircleShape
{
public:
	int id;
	player();
	void die() {}
	void update();
};

