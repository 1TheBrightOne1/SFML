#pragma once

#include <SFML/Graphics.hpp>
#include "Drawable.h"
#include "Kinematics.h"
#include "AnimationManager.h"

class Entity : public Drawable
{
protected:
	enum States
	{
		Idle
	};
	States m_state = Idle;
	Kinematics m_kinematics;
	AnimationManager m_animations;

	virtual void InitializeAnimations() = 0;
	virtual void UpdateState(const sf::Int32& elapsedTime) = 0;
	virtual void StartNewState() = 0;
public:
	Entity(const sf::Vector2f& startingPosition);
	void Update(const sf::Int32& elapsedTime);
};