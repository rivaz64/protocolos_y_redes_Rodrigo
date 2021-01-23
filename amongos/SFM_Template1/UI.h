#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"

class MenuManager;

using namespace std;

class UI
{
public:
	static void Init(sf::RenderWindow* window);
	static void Update();
	static void ChangeMenu(MenuManager* menu);
	static void Render(sf::RenderWindow* window);
	static void Destroy();
	
protected:

	static void a(vector<void*> z) { cout << "a" << endl; }
	static void b(vector<void*> z) { cout << "b" << endl; }
	static void c(vector<void*> z) { cout << "c" << endl; }
	static void d(vector<void*> z) { cout << "d" << endl; }

protected:
	static sf::RenderWindow* m_window;

	static MenuManager* m_menu;
};

