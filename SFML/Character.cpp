#include "Character.h"

Character::Character(const sf::Vector2f & startingPosition) : Entity(startingPosition)
{
}

void Character::Draw(sf::RenderWindow & window)
{
	window.draw(m_sprite);
}

void Character::Update(const sf::Int32 & elapsedTime)
{
	States newState = UpdateState(elapsedTime);
	if (newState != m_state)
	{
		m_state = newState;
		m_animations.SetActiveAnimation(newState);
		ChangeKinematicsState();
	}
	else
		m_kinematics.Update(elapsedTime);
	if (m_kinematics.GetVelocity().x < 0)
		m_animations.SetFlipped(true);
	else if (m_kinematics.GetVelocity().x > 0)
		m_animations.SetFlipped(false);
	m_animations.GetActiveFrame(elapsedTime, m_sprite);
	m_sprite.setPosition(m_kinematics.GetPosition());
}
