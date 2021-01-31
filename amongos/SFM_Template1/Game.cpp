#include "Game.h"
#include "Globals.h"
#include<fstream>
std::vector<room> Game::r = {};
sf::RenderWindow* Game::m_window;
sf::CircleShape Game::m_shape;
sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);
std::vector<player> Game::p;
void Game::run()
{
	init();

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_window->isOpen())
	{
		processEvents();

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate >= timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			gl::DeltaTime::m_time = timePerFrame.asSeconds();
			update();
		}
		render();
	}

	destroy();
}

void Game::init()
{
	m_window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Chess");
	for (int i = 0; i < 2; i++) {
		p.push_back(player());
		p[i].id = i;
	}
	load();
	/*m_shape.setFillColor(sf::Color::Red);
	m_shape.setPosition({100, 100});
	m_shape.setRadius(25);*/
}

void Game::update()
{
	for (player& a : p) {
		a.update();
	}
	if (Input::GetKeyPressed(sf::Keyboard::Key::P)) {
		r.push_back(room());
	}
	if (Input::GetKeyPressed(sf::Keyboard::Key::O)) {
		save();
	}
	for (room &a : r) {
		a.update();
	}
	Input::Update();
}

void Game::processEvents()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			Input::HandleInputs(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			Input::HandleInputs(event.key.code, false);
			break;
		case sf::Event::Closed:
			m_window->close();
			break;
		}
	}
}

void Game::render()
{
	m_window->clear();
	for (room &a : r) {
		m_window->draw(a);
	}
	for (player &a : p) {
		m_window->draw(a);
	}

	m_window->display();
}

void Game::destroy()
{
}

Game::~Game()
{
}

Game::Game()
{
}

void Game::save()
{
	fstream file;
	file.open("D://vs//amongos//map.txt");
	file << r.size()<<endl;
	for (room& a : r) {
		file << a.getPosition().x << " "<<a.getPosition().y << " " << a.getSize().x << " "<<a.getSize().y << endl;
	}
}

void Game::load()
{
	fstream file;
	file.open("D://vs//amongos//map.txt");
	int n;
	file >> n;
	sf::Vector2f v;
	for (int i = 0; i < n; i++) {
		r.push_back(room());
		file >> v.x;
		file >> v.y;
		r[i].setPosition(v);
		file >> v.x;
		file >> v.y;
		r[i].setSize(v);
	}
}
