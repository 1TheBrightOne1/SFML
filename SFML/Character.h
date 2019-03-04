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
	enum States
	{
		Idle
	};
	AnimationManager m_animations;
	States m_state = Idle;
	sf::Vector2i m_charSize;
	virtual Character::States UpdateState(const sf::Int32& elapsedTime) = 0;
	virtual void ChangeKinematicsState() = 0; //Called when a state is changed to make changes to kinematics
	virtual void InitializeAnimations() = 0;
public:
	Character(const sf::Vector2f& startingPosition);
	void Draw(sf::RenderWindow& window);
	void Update(const sf::Int32& elapsedTime);
};

