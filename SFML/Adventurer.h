#pragma once

#include "Character.h"

class Adventurer : public Character
{
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
	void UpdateState(const sf::Int32& elapsedTime);
	void StartNewState();
	void InitializeAnimations();
public:
	Adventurer(const sf::Vector2f& startingPos);
};