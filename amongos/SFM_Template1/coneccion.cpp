#include "coneccion.h"

void coneccion::enviar(mensaje m)
{
	sf::Packet pakete;
	pakete << m.velx;
	pakete<<m.vely;
	soket.send(pakete);
}

mensaje coneccion::recibir()
{
	sf::Packet pakete;
	soket.receive(pakete);
	mensaje m;
	pakete >> m.velx;
	pakete >> m.vely;
	return m;
}
