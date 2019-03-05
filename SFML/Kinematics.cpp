#include "Kinematics.h"

Kinematics::Kinematics(sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acc) :
	m_position(std::move(pos)), m_velocity(std::move(vel)), m_acceleration(std::move(acc))
{
}


Kinematics::~Kinematics()
{
}

void Kinematics::Update(const sf::Int32 & elapsedTime)
{
	float adjustedTime = elapsedTime / 1000.0f;
	m_position.x = m_position.x + m_velocity.x * adjustedTime + 1 / 2 * m_acceleration.x * adjustedTime * adjustedTime;
	m_position.y = m_position.y + m_velocity.y * adjustedTime + 1 / 2 * m_acceleration.y * adjustedTime * adjustedTime;

	m_velocity.x = m_velocity.x + m_acceleration.x * adjustedTime;
	m_velocity.y = m_velocity.y + m_acceleration.y * adjustedTime;

	if (m_position.y > 400)
	{
		m_position.y = 400;
		m_velocity.y = 0;
	}
}

void Kinematics::SetVelocity(sf::Vector2f newVel)
{
	m_velocity = std::move(newVel);
}

void Kinematics::SetAcceleration(sf::Vector2f newAcc)
{
	m_acceleration = std::move(newAcc);
}

void Kinematics::SetPosition(sf::Vector2f newPos)
{
	m_position = std::move(newPos);
}

void Kinematics::SetVelocity(Dimension dimension, float val)
{
	if (dimension == x)
		m_velocity.x = val;
	else
		m_velocity.y = val;
}
