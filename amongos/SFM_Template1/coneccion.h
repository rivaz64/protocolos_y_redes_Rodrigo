#pragma once
#include "SFML/Network.hpp"
#include "SFML/Graphics.hpp"
#endif // 
struct mensaje {
	float velx;
	float vely;
};
class coneccion
{
	sf::TcpSocket soket;
	sf::TcpListener listener;
public:
	void enviar(mensaje m);
	mensaje recibir();
};

