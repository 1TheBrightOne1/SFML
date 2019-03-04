#pragma once

#include <memory>
#include "Adventurer.h"

enum CharacterTypes
{
	Player
};

class CharacterBuilder
{
public:
	static std::unique_ptr<Character> BuildCharacter(CharacterTypes type);
};