#include "Adventurer.h"

Character::States Adventurer::UpdateState(const sf::Int32 & elapsedTime)
{
	bool leftClicked = sf::Mouse::isButtonPressed(sf::Mouse::Left);
	bool leftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
	bool rightPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
	bool upPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

	Adventurer::States newState = static_cast<Adventurer::States>(m_state);
	switch (m_state)
	{
	case Idle:
		if (leftClicked)
			newState = Attack1;
		else if (upPressed)
			newState = Jump;
		else if (leftPressed != rightPressed)
			newState = Run;
		break;
	case Run:
		if (leftClicked)
			newState = Attack1;
		else if (upPressed)
			newState = Jump;
		else if (!leftPressed && !rightPressed)
			newState = Idle;
		break;
	case Jump:
		if (leftClicked)
			newState = DownSmash;
		else if (m_animations.AnimationFinished())
			newState = Falling;
		break;
	case Falling:
		if (m_kinematics.GetVelocity().y == 0)
			newState = Idle;
		break;
	case Attack1:
		if (m_animations.AnimationFinished())
		{
			if (leftClicked)
				newState = Attack2;
			else if (upPressed)
				newState = Jump;
			else if (leftPressed != rightPressed)
				newState = Run;
			else
				newState = Idle;
		}
		break;
	case Attack2:
		if (m_animations.AnimationFinished())
			newState = Idle;
		break;
	case DownSmash:
		if (m_kinematics.GetVelocity().y == 0)
			newState = Idle;
		break;
	}
	return static_cast<Character::States>(newState);
}

void Adventurer::ChangeKinematicsState()
{
	switch (m_state)
	{
	case Idle:
		m_kinematics.SetVelocity(Kinematics::Dimension::x, 0);
		break;
	case Run:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			m_kinematics.SetVelocity(Kinematics::Dimension::x, -1 * m_moveSpeed);
		else
			m_kinematics.SetVelocity(Kinematics::Dimension::x, m_moveSpeed);
		break;
	case Attack1:
		m_kinematics.SetVelocity(Kinematics::Dimension::x, 0);
		break;
	case Jump:
		m_kinematics.SetVelocity(Kinematics::Dimension::y, -70);
		break;
	case DownSmash:
		m_kinematics.SetVelocity(Kinematics::Dimension::y, 1);
		break;
	}
}

void Adventurer::InitializeAnimations()
{
	sf::Texture texture;
	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(0, 0, m_charSize.x * 4, m_charSize.y));
	m_animations.AddAnimation(Idle, AnimationManager::Builder{ texture, 4, 150 }.SetFrameSize(m_charSize));

	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(m_charSize.x * 1, m_charSize.y * 1, m_charSize.x * 6, m_charSize.y));
	m_animations.AddAnimation(Run, AnimationManager::Builder{ texture, 6, 100 }.SetFrameSize(m_charSize));

	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(0, m_charSize.y * 2, m_charSize.x * 7, m_charSize.y * 3));
	m_animations.AddAnimation(Jump, AnimationManager::Builder{ texture, 8, 70 }.SetFrameSize(m_charSize).SetRepeat(false));

	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(0, m_charSize.y * 6, m_charSize.x * 7, m_charSize.y));
	m_animations.AddAnimation(Attack1, AnimationManager::Builder{ texture, 7, 70 }.SetFrameSize(m_charSize).SetRepeat(false));

	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(0, m_charSize.y * 7, m_charSize.x * 4, m_charSize.y * 1));
	m_animations.AddAnimation(Attack2, AnimationManager::Builder{ texture, 4, 70 }.SetFrameSize(m_charSize).SetRepeat(false));

	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(0, m_charSize.y * 14, m_charSize.x * 7, m_charSize.y * 2));
	m_animations.AddAnimation(DownSmash, AnimationManager::Builder{ texture, 4, 70 }.SetFrameSize(m_charSize).SetInterruptable(false).SetRepeat(false).SetOriginOffset(m_charSize.x * 3));

	texture.loadFromFile("Assets/AdventurerSheet.png", sf::IntRect(m_charSize.x * 1, m_charSize.y * 3, m_charSize.x * 2, m_charSize.y));
	m_animations.AddAnimation(Falling, AnimationManager::Builder{ texture, 2, 70 }.SetFrameSize(m_charSize));
}

Adventurer::Adventurer(const sf::Vector2f & startingPos) : Character(startingPos)
{
	m_charSize = sf::Vector2i(50, 37);
	InitializeAnimations();
}
