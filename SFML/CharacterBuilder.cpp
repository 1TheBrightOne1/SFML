#include "CharacterBuilder.h"

std::unique_ptr<Character> CharacterBuilder::BuildCharacter(CharacterTypes type)
{
	if (type == Player)
	{
		std::unique_ptr<Character> newPlayer = std::make_unique<Adventurer>(sf::Vector2f(400, 400));
		return newPlayer;
	}
	else if (type == Skeleton)
	{
		std::unique_ptr<Character> newSkeleton = std::make_unique<class Skeleton>(sf::Vector2f(400, 400));
		return newSkeleton;
	}
}
