#include "room.h"
#include"Game.h"
#include"Globals.h"
room::room() {
	setSize({ 100,100 });
	setPosition({ 100,100 });
	setFillColor(sf::Color::White);
	setOrigin(50, 50);
}

void room::update()
{
	if (v) {
		setPosition({ (float)sf::Mouse::getPosition(*Game::getWindow()).x , (float)sf::Mouse::getPosition(*Game::getWindow()).y  });
		if (Input::GetKey(sf::Keyboard::Key::W)) {
			setSize({ getSize().x, getSize().y - 1 });
		}
		if (Input::GetKey(sf::Keyboard::Key::S)) {
			setSize({ getSize().x, getSize().y+ 1 });
		}
		if (Input::GetKey(sf::Keyboard::Key::A)) {
			setSize({ getSize().x-1, getSize().y  });
		}
		if (Input::GetKey(sf::Keyboard::Key::D)) {
			setSize({ getSize().x+1, getSize().y - 1 });
		}
	}
	if (this->getGlobalBounds().intersects(sf::FloatRect((sf::Vector2f)sf::Mouse::getPosition(*Game::getWindow()), { 6.f,6.f })) && Input::GetMouseButtonDown(0)) {
		v = !v;
		posi = { sf::Mouse::getPosition(*Game::getWindow()).x - getPosition().x,sf::Mouse::getPosition(*Game::getWindow()).y - getPosition().y };
	}
}
