#include "TextureManager.h"



TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

void TextureManager::Cleanup(const TextureWrapper & removedTexture)
{
	auto texture = std::find(m_textures.begin(), m_textures.end(), [&removedTexture](std::shared_ptr<TextureWrapper> texture) {return texture->path == removedTexture.path; });
	
}

std::shared_ptr<TextureWrapper> TextureManager::CreateTexture(const std::string & location)
{
	auto texture = std::find(m_textures.begin(), m_textures.end(), [&location](std::shared_ptr<TextureWrapper> texture) {return texture->path == location; });
	if (texture != m_textures.end())
		return *texture;
	else
		m_textures.emplace_back(std::make_shared<TextureWrapper>(location));
	return m_textures[m_textures.size() - 1];
}
