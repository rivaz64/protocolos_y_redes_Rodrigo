#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "UIShape.h"

using namespace std;

class Button
{
public:
	enum class TextAlignment {
		NONE = -1, LEFT, CENTER, RIGHT
	};
	enum class SelectorAligment {
		NONE = -1, UP, LEFT, CENTER, RIGHT, DOWN
	};
	Button() {}
	Button(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape,
		string text, sf::Font* font, sf::Color textColor, unsigned int minSize, unsigned int maxSize, TextAlignment alignment,
		sf::Texture* selectorTex, sf::Vector2f selectorSize, SelectorAligment selectorAlign, float selectorDistance);
	Button(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape,
		string text, sf::Font* font, sf::Color textColor, unsigned int minSize, unsigned int maxSize, TextAlignment alignment);
	Button(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape,
		sf::Texture* selectorTex, sf::Vector2f selectorSize, SelectorAligment selectorAlign, float selectorDistance);
	Button(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape);
	~Button();

	void Init(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape,
		string text, sf::Font* font, sf::Color textColor, unsigned int minSize, unsigned int maxSize, TextAlignment alignment,
		sf::Texture* selectorTex, sf::Vector2f selectorSize, SelectorAligment selectorAlign, float selectorDistance);
	void Init(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape,
		string text, sf::Font* font, sf::Color textColor, unsigned int minSize, unsigned int maxSize, TextAlignment alignment);
	void Init(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape,
		sf::Texture* selectorTex, sf::Vector2f selectorSize, SelectorAligment selectorAlign, float selectorDistance);
	void Init(void (*function)(std::vector<void*>), std::vector<void*> parameters, sf::RenderWindow* window,
		UIShape shape);
	bool Update();
	void setFillColor(const sf::Color fillColor);
	void setOutlineColor(const sf::Color outlineColor);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void setTranform(sf::IntRect buttonTransform);
	void setText(string text, sf::Font* font, sf::Color textColor, unsigned int minSize, unsigned int maxSize, TextAlignment alignment);
	void setSelector(sf::Texture* selectorTex, sf::Vector2f selectorSize, SelectorAligment selectorAlign, float selectorDistance);
	sf::Color getFillColor() { return m_buttonShape.getFillColor(); }
	sf::Color getOutlineColor() { return m_buttonShape.getOutlineColor(); }
	sf::Vector2i getPositioni() { return m_buttonShape.getPositioni(); }
	sf::Vector2i getSizei() { return m_buttonShape.getSizei(); }
	sf::IntRect getTranformi() { return m_buttonShape.getTranformi(); }
	sf::Vector2f getPositionf() { return m_buttonShape.getPositionf(); }
	sf::Vector2f getSizef() { return m_buttonShape.getSizef(); }
	sf::FloatRect getTranformf() { return m_buttonShape.getTranformf(); }
	void ConectUp(Button* conection);
	void ConectLeft(Button* conection);
	void ConectDown(Button* conection);
	void ConectRight(Button* conection);
	void Render(sf::RenderWindow* window);
	void Destroy();
private:
	bool isMouseOver();
	bool isClicked();
	void onClick();
	void setPositionRect(sf::Vector2f position); 
	void AlignText(TextAlignment aligment);
	void AlignSelector(SelectorAligment selectorAlign, float selectorDistance);
private:
	friend class UI;
	friend class GameOver_menu;
	friend class MenuManager;

	UIShape m_buttonShape;
	sf::Text m_text;
	TextAlignment m_textAligment = TextAlignment::NONE;
	sf::RectangleShape m_selector;
	SelectorAligment m_selectorAligment = SelectorAligment::NONE;
	float m_selectorDistance = 0;

	void (*m_function)(std::vector<void*>) = nullptr;
	std::vector<void*> m_parameters;
	bool isPressed = false;
	bool isSelected = false;

	Button* m_selectionUp = nullptr;
	Button* m_selectionLeft = nullptr;
	Button* m_selectionDown = nullptr;
	Button* m_selectionRight = nullptr;
	/*bool m_isSelectingUp = false, m_isPressedUp = false;
	bool m_isSelectingLeft = false, m_isPressedLeft = false;
	bool m_isSelectingDown = false, m_isPressedDown = false;
	bool m_isSelectingRight = false, m_isPressedRight = false;
	bool m_isSelectingThis = false, m_isPressedSelection = false;*/

	sf::RenderWindow* m_window = nullptr;
};

