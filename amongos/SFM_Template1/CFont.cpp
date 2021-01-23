#include "CFont.h"
#include <iostream>

map<string, sf::Font> CFont::m_fonts{};
void CFont::AddFont(string name, string fontName)
{
	sf::Font font;
	if (!font.loadFromFile(fontName)) {
		cout << "Font not found" << endl;
	}
	m_fonts.insert(make_pair(name, font));
}

void CFont::AddFont(string name, sf::Font font)
{
	m_fonts.insert(make_pair(name, font));
}

void CFont::AddFont(string name, sf::Text text)
{
	sf::Font font = *text.getFont();
	m_fonts.insert(make_pair(name, font));
}

sf::Font* CFont::getFont(string name)
{
	return &m_fonts[name];
}
