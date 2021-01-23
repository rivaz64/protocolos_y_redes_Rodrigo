#include "player.h"
#include"Globals.h"
#include"Game.h"
player::player()
{
	setFillColor(sf::Color::Red);
	setRadius(6);
	this->setOrigin(3, 3);
	this->setPosition({ 100,100 });
}

void player::update()
{
	sf::Vector2f movement = { 0,0 };
	sf::Vector2f past = getPosition();
	if (id == 0) {
		if (Input::GetKey(sf::Keyboard::Key::W)) {
			movement.y -= 1;
		}
		if (Input::GetKey(sf::Keyboard::Key::S)) {
			movement.y += 1;
		}
		if (Input::GetKey(sf::Keyboard::Key::A)) {
			movement.x -= 1;
		}
		if (Input::GetKey(sf::Keyboard::Key::D)) {
			movement.x += 1;
		}
		if (Input::GetKey(sf::Keyboard::Key::Q)) {
			for (player& a : Game::p) {
				if (&a != this && sqrt(pow(getPosition().x - a.getPosition().x, 2) + pow(getPosition().y - a.getPosition().y, 2))<36) {
					a.die();
				}
			}
		}
	}
	
	move(movement);
	bool v = false;
	for (room& a : Game::r) {
		if (a.getGlobalBounds().intersects(getGlobalBounds())){
			v = true;
			break;
		}
	}
	if (!v) {
		setPosition(past);
	}
}
