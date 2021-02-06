#include <SFML/Graphics.hpp>
#include "Game.h"
#include "networkmanager.h"
#include<iostream>
sf::UdpSocket socket;
sf::UdpSocket sockete;
void reciver() {
	char data[100];
	std::size_t received;
	sf::IpAddress sender;
	unsigned short port;
	while (true) {
		socket.receive(data, 100, received, sender, port);
		std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;
	}
}
int main()
{
	
	/*d.conect(54000);
	c.conect(54001);
	d.escuchar();
	c.enviar();
	d.close();*/
	Game::run();
	return 0;
}