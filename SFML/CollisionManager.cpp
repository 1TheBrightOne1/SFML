#include "CollisionManager.h"

Collision * CollisionManager::AddCollision(const sf::IntRect & hitBox, Collision::RegisteredType boxType)
{
	m_collisions.emplace_back(Collision(hitBox, boxType));
	return &m_collisions[m_collisions.size() - 1];
}

void CollisionManager::RemoveCollision(Collision * collision)
{
	auto found = std::find(m_collisions.begin(), m_collisions.end(), *collision);
	if (found != m_collisions.end())
		m_collisions.erase(found);
}

bool CollisionManager::CheckCollisions(const Collision * testCollision, const Collision* resultCollision, Collision::RegisteredType & coolisionType, Collision::Direction direction)
{
	for (auto hitBox : m_collisions)
	{
		if (testCollision != &hitBox)
		{
			if ()
		}
	}
	return false;
}
