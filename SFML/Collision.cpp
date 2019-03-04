#include "Collision.h"

Collision::Collision(const sf::IntRect & hitBox, RegisteredType type) : 
	m_hitBox(hitBox), m_type(type)
{
}

bool Collision::TestCollision(const Collision & testCollision, Collision::Direction& direction)
{
	if (m_hitBox.top > testCollision.m_hitBox.top + testCollision.m_hitBox.height ||
		m_hitBox.top + m_hitBox.height < testCollision.m_hitBox.top ||
		m_hitBox.left > testCollision.m_hitBox.left + testCollision.m_hitBox.width ||
		m_hitBox.left + m_hitBox.width < testCollision.m_hitBox.left)
		return false;
	else
	{
		if (m_hitBox.top + m_hitBox.height < testCollision.m_hitBox.top)
		{

		}
	}
}
