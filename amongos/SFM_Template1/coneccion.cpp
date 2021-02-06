#include "coneccion.h"
#include<iostream>
coneccion::coneccion()
{
	
}

void coneccion::enviar()
{
	char data[100] = "qwerty";
	//sf::IpAddress recipient = sf::IpAddress::getLocalAddress();
	sf::IpAddress recipient = "127.0.0.1";
	unsigned short port = 54000;
	if (socket.send(data, 100, recipient, port) != sf::Socket::Done)
	{
		std::cout << "error0" << std::endl;
	}
	
}

void coneccion::recibir(void* p)
{
	char data[100];
	std::size_t received;
	//sf::UdpSocket socket;
	sf::IpAddress sender;
	unsigned short port;
	while (true) {
		if (((sf::UdpSocket*)p)->receive(data, 100, received, sender, port) != sf::Socket::Done)
		{
			std::cout << "error1" << std::endl;
		}
		std::cout << data << std::endl;
		//std::cout << "Received " << received << " bytes from " << sender << " on port " << port << std::endl;
	}
	
}

void coneccion::conect(int p)
{
	if (socket.bind(p) != sf::Socket::Done)
	{
		std::cout << "error" << std::endl;
	}
}

void coneccion::escuchar()
{
	//t = std::make_shared<thread>(thread(&recibir));
	t = std::make_shared<thread>(thread(&coneccion::recibir,&socket));
}

void coneccion::close()
{
	t->join();
}
