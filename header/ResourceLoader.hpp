#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <SFML/Graphics.hpp>
#include <string>

typedef char byte;

class ResourceLoader
{
private:
	std::string resourcePack;
public:
	ResourceLoader(const ResourceLoader &loader) = delete;
	void operator=(const ResourceLoader &loader) = delete;

	ResourceLoader(const std::string resourcePack);
	~ResourceLoader();

	sf::Texture loadTexture(const std::string name);
	sf::Font loadFont(const std::string name);
	byte* load(const std::string fileName, size_t *size);
private:

};

#endif //RESOURCELOADER_HPP
