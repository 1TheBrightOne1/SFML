#include "Platform.h"



Platform::Platform(const sf::Vector2f & startingPosition) : Entity(startingPosition)
{
	m_texture.loadFromFile("Assets/Jungle Tileset.png", sf::IntRect{ 145, 17, 15, 15 });
	m_sprite.setTexture(m_texture);
	m_texture.setRepeated(true);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 100, 15));
}


Platform::~Platform()
{
}
