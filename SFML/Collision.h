#pragma once

#include <vector>
#include <functional>
#include <SFML/Graphics.hpp>

using namespace std::placeholders;
class Collision
{
	friend class CollisionManager;
	enum RegisteredType
	{
		Player,
		Static,
		Projectiles,
		Enemy
	};
	enum Direction
	{
		Top,
		Bottom,
		Left,
		Right
	};
	const sf::IntRect& m_hitBox;
	RegisteredType m_type;
	std::function<void(RegisteredType, Direction)> m_callback;
	Collision(const sf::IntRect& hitBox, RegisteredType type);
public:
	void Notify(RegisteredType collisionType, Direction direction);
	bool TestCollision(const Collision& testCollision, Collision::Direction&);
};