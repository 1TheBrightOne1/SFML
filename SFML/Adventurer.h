#pragma once

#include "Character.h"

class Adventurer : public Character
{
	int m_moveSpeed = 60;
	enum States
	{
		Idle,
		Run,
		Attack1,
		Attack2,
		Attack3,
		Falling,
		Jump,
		Slide,
		Die,
		Crouch,
		DownSmash,
		DownSmashCont,
		DoubleJump
	};
	Character::States UpdateState(const sf::Int32& elapsedTime);
	void ChangeKinematicsState();
	void InitializeAnimations();
public:
	Adventurer(const sf::Vector2f& startingPos);
};