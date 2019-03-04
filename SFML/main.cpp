#include <SFML/Graphics.hpp>
#include <vector>
#include "CharacterBuilder.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Adventure");
	std::unique_ptr<Character> characters;
	characters = std::move(CharacterBuilder::BuildCharacter(Player));

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asSeconds() > 0.05f)
		{
			characters->Update(clock.getElapsedTime().asMilliseconds());
			/*std::for_each(characters.begin(), characters.end(), [&clock](std::unique_ptr<Character> character) {
				character->Update(clock.getElapsedTime().asMilliseconds());
			});*/
			clock.restart();
		}

		window.clear();
		characters->Draw(window);
		/*std::for_each(characters.begin(), characters.end(), [&window](std::unique_ptr<Character> character) {
			character->Draw(window);
		});*/
		window.display();
	}

	return 0;
}