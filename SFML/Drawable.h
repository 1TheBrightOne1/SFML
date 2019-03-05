#pragma once
#include <SFML/Graphics.hpp>

class Drawable
{
protected:
	sf::Sprite m_sprite;
	bool m_isVisible = true;
public:
	Drawable();
	void Draw(sf::RenderWindow& window);
	void SetVisible(bool val) { m_isVisible = val; }
};