#pragma once

#include "Character.h"

class Skeleton : public Character
{
	enum States
	{
		Idle,
		Walk,
		Attack,
		Hit,
		Die
	};
	void UpdateState(const sf::Int32& elapsedTime) {}
	void StartNewState() {}
	void InitializeAnimations();
public:
	Skeleton(const sf::Vector2f& startingPos);
};