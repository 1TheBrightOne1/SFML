#include "CharacterBuilder.h"

std::unique_ptr<Character> CharacterBuilder::BuildCharacter(CharacterTypes type)
{
	if (type == Player)
	{
		std::unique_ptr<Character> newPlayer = std::make_unique<Adventurer>(sf::Vector2f(400, 400));
		return newPlayer;
	}
}
