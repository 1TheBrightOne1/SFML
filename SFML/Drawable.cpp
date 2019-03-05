#include "Drawable.h"



Drawable::Drawable()
{
}

void Drawable::Draw(sf::RenderWindow & window)
{
	if (m_isVisible)
		window.draw(m_sprite);
}