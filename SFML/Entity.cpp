#include "Entity.h"

Entity::Entity(const sf::Vector2f & startingPosition) : m_kinematics(startingPosition)
{
}

void Entity::Update(const sf::Int32 & elapsedTime)
{
	//Check for state change
	UpdateState(elapsedTime);
	
	m_kinematics.Update(elapsedTime);

	//Reverse images if needed before getting new animation
	if (m_animations.Count() > 0)
	{
		if (m_kinematics.GetVelocity().x < 0)
			m_animations.SetFlipped(true);
		else if (m_kinematics.GetVelocity().x > 0)
			m_animations.SetFlipped(false);
		m_animations.GetActiveFrame(elapsedTime, m_sprite);
	}

	//Update the sprite
	m_sprite.setPosition(m_kinematics.GetPosition());
}
