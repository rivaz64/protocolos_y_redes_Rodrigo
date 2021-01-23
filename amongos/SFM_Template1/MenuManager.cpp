#include "MenuManager.h"

void MenuManager::Init()
{
}

void MenuManager::Reposition(sf::Vector2f wordlPosition)
{
	for (Button& button : m_buttons) {
		button.setPosition(wordlPosition);
	}
	for (UIShape& shape : m_shapes) {
		shape.Reposition(wordlPosition);
	}
}

void MenuManager::Update()
{
	for (Button& button : m_buttons) {
		if (button.Update())
			break;
	}
	for (Button& button : m_buttons) {
		if (button.isMouseOver()) {
			for (Button& but : m_buttons) {
				but.isSelected = false;
			}
			button.isSelected = true;
		}
	}
	for (UIShape& shape : m_shapes) {
		shape.Update();
	}
}

void MenuManager::Render(sf::RenderWindow* window)
{
	for (UIShape& shape : m_shapes) {
		shape.Render(window);
	}
	for (Button& button : m_buttons) {
		button.Render(window);
	}
}

void MenuManager::Destroy()
{
	for (Button& button : m_buttons) {
		button.Destroy();
	}
	for (UIShape& shape : m_shapes) {
		shape.Destroy();
	}
	m_buttons.clear();
	m_shapes.clear();
}
