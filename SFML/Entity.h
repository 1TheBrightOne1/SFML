#pragma once

#include <SFML/Graphics.hpp>
#include "Kinematics.h"

class Entity
{
protected:
	sf::Sprite m_sprite;
	Kinematics m_kinematics;
	sf::Vector2i m_charSize;
public:
	Entity(const sf::Vector2f& startingPosition);
	void Draw(sf::RenderWindow& window);
	void Update(const sf::Int32& elapsedTime);
};