#pragma once

#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include "SFML/Graphics.hpp"

struct TextureWrapper
{
	TextureWrapper(const std::string& location);
	~TextureWrapper();
	const sf::Texture texture;
	const std::string path;
};

class TextureManager
{
	std::vector<std::shared_ptr<TextureWrapper>> m_textures;
public:
	TextureManager();
	~TextureManager();
	void Cleanup(const TextureWrapper& texture);
	std::shared_ptr<TextureWrapper> CreateTexture(const std::string& location);
};

