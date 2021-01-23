#include "UIShape.h"

UIShape::UIShape()
{
	Init();
}

UIShape::UIShape(sf::FloatRect shapeTransform, sf::Texture* shapeTex)
{
	Init(shapeTransform, shapeTex);
}

UIShape::UIShape(sf::FloatRect shapeTransform, sf::Color fillColor, sf::Color outlineColor, float outlineTickness)
{
	Init(shapeTransform, fillColor, outlineColor, outlineTickness);
}

UIShape::~UIShape()
{
}

void UIShape::Init()
{
}

void UIShape::Init(sf::FloatRect shapeTransform, sf::Texture* shapeTex)
{
	m_shape.setSize({ shapeTransform.width, shapeTransform.height });
	m_position = { shapeTransform.left, shapeTransform.top };
	m_shape.setPosition(m_position);
	m_shape.setTexture(shapeTex);
}

void UIShape::Init(sf::FloatRect shapeTransform, sf::Color fillColor, sf::Color outlineColor, float outlineTickness)
{
	m_shape.setSize({ shapeTransform.width, shapeTransform.height });
	m_position = { shapeTransform.left, shapeTransform.top };
	m_shape.setPosition(m_position);
	m_shape.setFillColor(fillColor);
	m_shape.setOutlineColor(outlineColor);
	m_shape.setOutlineThickness(outlineTickness);
}

void UIShape::Reposition(sf::Vector2f wordlPosition)
{
	m_shape.setPosition(wordlPosition + m_position);
}

void UIShape::Update()
{
}

void UIShape::setFillColor(const sf::Color fillColor)
{
	m_shape.setFillColor(fillColor);
}

void UIShape::setOutlineColor(const sf::Color outlineColor)
{
	m_shape.setOutlineColor(outlineColor);
}

void UIShape::setPosition(sf::Vector2f position)
{
	m_shape.setPosition(position + m_position);
}

void UIShape::setPositionRect(sf::Vector2f position)
{
	move(position - m_position);
	m_position = position;
}

void UIShape::setSize(sf::Vector2f size)
{
	m_shape.setSize(size);
}

void UIShape::setTranform(sf::IntRect buttonTransform)
{
	m_position = { (float)buttonTransform.left, (float)buttonTransform.top };
	m_shape.setPosition(m_position);
	m_shape.setSize({ (float)buttonTransform.width, (float)buttonTransform.height });
}

void UIShape::move(sf::Vector2f moved)
{
	m_shape.move(moved);
	m_position += moved;
}

void UIShape::Render(sf::RenderWindow* window)
{
	window->draw(m_shape);
}

void UIShape::Destroy()
{
}
