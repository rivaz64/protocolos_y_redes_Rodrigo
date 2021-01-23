#pragma once
#include <SFML/Graphics.hpp>

class UIShape
{
public:
	UIShape();
	UIShape(sf::FloatRect shapeTransform, sf::Texture* shapeTex);
	UIShape(sf::FloatRect shapeTransform, sf::Color fillColor, sf::Color outlineColor, float outlineTickness);
	~UIShape();
	void Init();
	void Init(sf::FloatRect shapeTransform, sf::Texture* shapeTex);
	void Init(sf::FloatRect shapeTransform, sf::Color fillColor, sf::Color outlineColor, float outlineTickness);
	void Reposition(sf::Vector2f wordlPosition);
	void Update();
	void setFillColor(const sf::Color fillColor);
	void setOutlineColor(const sf::Color outlineColor);
	void setPosition(sf::Vector2f position);
	void setPositionRect(sf::Vector2f position);
	void setSize(sf::Vector2f size);
	void setTranform(sf::IntRect buttonTransform);
	sf::Color getFillColor() { return m_shape.getFillColor(); }
	sf::Color getOutlineColor() { return m_shape.getOutlineColor(); }
	sf::Vector2i getPositioni() { return sf::Vector2i(m_shape.getPosition().x, m_shape.getPosition().y); }
	sf::Vector2i getSizei() { return sf::Vector2i(m_shape.getSize().x, m_shape.getSize().y); }
	sf::IntRect getTranformi() { return sf::IntRect(m_position.x, m_position.y, m_shape.getSize().x, m_shape.getSize().y); }
	sf::Vector2f getPositionf() { return sf::Vector2f(m_shape.getPosition().x, m_shape.getPosition().y); }
	sf::Vector2f getSizef() { return sf::Vector2f(m_shape.getSize().x, m_shape.getSize().y); }
	sf::FloatRect getTranformf() { return sf::FloatRect(m_position.x, m_position.y, m_shape.getSize().x, m_shape.getSize().y); }
	void move(sf::Vector2f moved);
	void Render(sf::RenderWindow* window);
	void Destroy();
private:
	sf::RectangleShape m_shape;
	sf::Vector2f m_position;
};

