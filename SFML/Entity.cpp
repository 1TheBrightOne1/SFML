#include "Entity.h"

Entity::Entity(const sf::Vector2f & startingPosition) : m_kinematics(startingPosition)
{
}

void Entity::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Entity::Update(const sf::Int32 & elapsedTime)
{
	m_kinematics.Update(elapsedTime);
}
