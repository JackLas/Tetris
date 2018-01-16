#include "Block.hpp"

Block::Block()
{
}

Block::Block(const sf::Texture &texture)
{
	sprite.setTexture(texture);
}

Block::~Block()
{
}

void Block::setBuildingPosition(const sf::Vector2f position)
{
	buildingPosition = position;
}

sf::Vector2f Block::getBuildingPosition()
{
	return buildingPosition;
}

void Block::setPixelPosition(const sf::Vector2f position)
{
	sprite.setPosition(position);
}

void Block::setTexture(const sf::Texture &texture)
{
	sprite.setTexture(texture);
}

void Block::setColor(const sf::Color color)
{
	sprite.setColor(color);
}

void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
}