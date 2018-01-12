#include "ResourceLoader.hpp"

ResourceLoader::ResourceLoader()
{
}

ResourceLoader::~ResourceLoader()
{
}

sf::Texture ResourceLoader::loadTexture(const std::string name)
{
	sf::Texture texture;
	texture.loadFromFile(name);
	return texture;
}