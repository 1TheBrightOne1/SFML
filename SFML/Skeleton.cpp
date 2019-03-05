#include "Skeleton.h"

void Skeleton::InitializeAnimations()
{
	sf::Texture texture;
	sf::Vector2i frameSize{ 43, 37 };
	texture.loadFromFile("Assets/Skeleton/Skeleton Attack.png", sf::IntRect(0, 0, frameSize.x * 17, frameSize.y));
	m_animations.AddAnimation(Idle, AnimationManager::Builder{ texture, 17, 150}.SetFrameSize(frameSize));
}

Skeleton::Skeleton(const sf::Vector2f & startingPos) : Character(startingPos)
{
	InitializeAnimations();
}
