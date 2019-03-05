#include <SFML/Graphics.hpp>
#include <vector>
#include "CharacterBuilder.h"
#include "Platform.h"
int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Adventure");
	std::vector<std::unique_ptr<Character>> characters;
	std::vector<std::unique_ptr<Entity>> entities;

	entities.emplace_back(std::make_unique<Platform>(sf::Vector2f{ 0, 0 }));
	characters.push_back(std::move(CharacterBuilder::BuildCharacter(Player)));
	characters.push_back(std::move(CharacterBuilder::BuildCharacter(Skeleton)));

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
			for(auto& character : characters)
				character->Update(clock.getElapsedTime().asMilliseconds());
			for(auto& entity : entities)
				entity->Update(clock.getElapsedTime().asMilliseconds());
			clock.restart();
		}

		window.clear();
		for(auto& character : characters)
			character->Draw(window);
		for (auto& entity : entities)
			entity->Draw(window);
		window.display();
	}

	return 0;
}