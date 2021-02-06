#pragma once
#include <SFML/Graphics.hpp>
#include"player.h"
#include"room.h"
#include "coneccion.h"
class Game
{
public:
	static void run();

	static sf::RenderWindow* getWindow() { return m_window; }

	~Game();
	Game();
	static coneccion c;
	static coneccion d;
	static std::vector<player> p;
	static void save();
	static void load();
	static std::vector<room> r;
	static void init();
	static void update();
	static void processEvents();
	static void render();
	static void destroy();

private:
	static sf::RenderWindow* m_window;

	static sf::CircleShape m_shape;

	static sf::Time timePerFrame;
};

