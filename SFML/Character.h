#pragma once

#include <map>
#include <string>
#include <deque>
#include <iostream>
#include <memory>
#include "Entity.h"
#include "AnimationManager.h"

class Character : public Entity
{
protected:
	int m_moveSpeed = 90;
public:
	Character(const sf::Vector2f& startingPosition);
	void Draw(sf::RenderWindow& window);
};

