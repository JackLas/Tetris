#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>

class Block: public sf::Drawable
{
private:
	sf::Sprite sprite;
	sf::Vector2i buildingPosition;
public:
	Block(const Block &block);
	void operator=(const Block &block);

	Block();
	Block(const sf::Texture &texture);
	~Block();

	void setBuildingPosition(const sf::Vector2i &position);
	sf::Vector2i getBuildingPosition();
	void setPixelPosition(const sf::Vector2i &position);
	void setTexture(const sf::Texture &texture);
	void setColor(const sf::Color &color);
	const sf::Sprite& getSprite();
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
};

#endif //BLOCK_HPP