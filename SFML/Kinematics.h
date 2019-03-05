#pragma once

#include <SFML/Graphics.hpp>

class Kinematics
{
	sf::Vector2f m_position;
	sf::Vector2f m_velocity;
	sf::Vector2f m_acceleration;
public:
	enum Dimension
	{
		x,
		y
	};
	Kinematics(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f vel = sf::Vector2f(0, 0), sf::Vector2f acc = sf::Vector2f(0, 200.0f));
	~Kinematics();
	void Update(const sf::Int32& elapsedTime);
	void SetVelocity(sf::Vector2f newVel);
	void SetAcceleration(sf::Vector2f newAcc);
	void SetPosition(sf::Vector2f newPos);
	void SetVelocity(Dimension dimension, float val);
	sf::Vector2f GetPosition() { return m_position; }
	sf::Vector2f GetVelocity() { return m_velocity; }
};

