#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;

class CFont
{
public:
	static void AddFont(string name, string fontName);
	static void AddFont(string name, sf::Font font);
	static void AddFont(string name, sf::Text text);
	static sf::Font* getFont(string name);
private:
	static map<string, sf::Font> m_fonts;
};

