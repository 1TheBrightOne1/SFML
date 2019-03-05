#include "Character.h"

Character::Character(const sf::Vector2f & startingPosition) : Entity(startingPosition)
{
}

void Character::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}
