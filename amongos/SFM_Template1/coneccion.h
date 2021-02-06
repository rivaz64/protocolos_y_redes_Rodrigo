#pragma once
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#include<thread>
#include<memory>
using std::thread;
using std::shared_ptr;
struct mensaje {
	float velx;
	float vely;
};
class coneccion
{
	//
	sf::UdpSocket socket;
	
	//sf::UcpListener listener;
public:
	
	shared_ptr<thread> t;
	shared_ptr<int> i;
	coneccion();
	void enviar();
	static void recibir(void* p);
	void conect(int p);
	void escuchar();
	void close();
};

