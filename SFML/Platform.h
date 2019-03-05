#pragma once
#include "Entity.h"
class Platform : public Entity
{
	sf::Texture m_texture;
	void InitializeAnimations() {}
	void UpdateState(const sf::Int32& elapsedTime) {}
	void StartNewState(){}
public:
	Platform(const sf::Vector2f & startingPosition);
	~Platform();
};

