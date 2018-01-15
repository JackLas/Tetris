#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>

class Block: public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Vector2f buildingPosition;
public:
	Block(const Block &block) = delete;
	void operator=(const Block &block) = delete;

	Block();
	Block(const sf::Texture &texture);
	~Block();

	void setBuildingPosition(const sf::Vector2f position);
	sf::Vector2f getBuildingPosition();
	void setPixelPosition(const sf::Vector2f position);
	void setTexture(const sf::Texture &texture);
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
};

#endif //BLOCK_HPP