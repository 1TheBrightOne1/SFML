#pragma once

#include <memory>
#include "Adventurer.h"
#include "Skeleton.h"

enum CharacterTypes
{
	Player,
	Skeleton
};

class CharacterBuilder
{
public:
	static std::unique_ptr<Character> BuildCharacter(CharacterTypes type);
};