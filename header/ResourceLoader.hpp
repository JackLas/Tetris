#ifndef RESOURCELOADER_HPP
#define RESOURCELOADER_HPP

#include <SFML\Graphics.hpp>
#include <string>

class ResourceLoader
{
private:
public:
	ResourceLoader(const ResourceLoader& loader) = delete;
	void operator=(const ResourceLoader& loader) = delete;

	ResourceLoader();
	~ResourceLoader();

	sf::Texture loadTexture(const std::string name);
};

#endif //RESOURCELOADER_HPP