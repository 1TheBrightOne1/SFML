#pragma once

#include <vector>
#include <algorithm>
#include "Collision.h"

class CollisionManager
{
	static std::vector<Collision> m_collisions;
public:
	static Collision* AddCollision(const sf::IntRect& hitBox, Collision::RegisteredType boxType);
	static void RemoveCollision(Collision* collision);
	static bool CheckCollisions(const Collision* testCollision, const Collision* resultCollision, Collision::RegisteredType& coolisionType, Collision::Direction direction);
};