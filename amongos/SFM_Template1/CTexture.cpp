#include "CTexture.h"

map<string, sf::Texture> CTexture::m_textures{};
void CTexture::AddTexture(string name, string fileName)
{
	sf::Texture tex;
	if (!tex.loadFromFile(fileName)) {
		cout << "archivo no encontrado" << endl;
		return;
	}
	m_textures.insert(make_pair(name, tex));
}

void CTexture::AddTexture(string name, sf::Texture tex)
{
	m_textures.insert(make_pair(name, tex));
}

void CTexture::AddTexture(string name, sf::RectangleShape shape)
{
	sf::Texture tex = *shape.getTexture();
	m_textures.insert(make_pair(name, tex));
}

void CTexture::AddTexture(string name, sf::CircleShape shape)
{
	sf::Texture tex = *shape.getTexture();
	m_textures.insert(make_pair(name, tex));
}

void CTexture::AddTexture(string name, sf::Image image)
{
	sf::Texture tex;
	if (!tex.loadFromImage(image)) {
		cout << "imagen no valida" << endl;
		return;
	}
	m_textures.insert(make_pair(name, tex));
}

sf::Texture* CTexture::getTexture(string name)
{
	if (m_textures.find(name) != m_textures.end()) {
		return &m_textures[name];
	}
	cout << "Textura no existente" << endl;
	return new sf::Texture();
}
