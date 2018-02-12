#include "Block.hpp"

Block::Block()
{
}

Block::Block(const sf::Texture &texture)
{
	sprite.setTexture(texture);
}

Block::Block(const Block &block)
{
	*this = block;
}

void Block::operator=(const Block &block)
{
	sprite = block.sprite;
	buildingPosition = block.buildingPosition;
}

Block::~Block()
{
}

void Block::setBuildingPosition(const sf::Vector2i &position)
{
	buildingPosition = position;
}

sf::Vector2i Block::getBuildingPosition()
{
	return buildingPosition;
}

void Block::setPixelPosition(const sf::Vector2i &position)
{
	sprite.setPosition(static_cast<float>(position.x), static_cast<float>(position.y));
}

void Block::setTexture(const sf::Texture &texture)
{
	sprite.setTexture(texture);
}

void Block::setColor(const sf::Color &color)
{
	sprite.setColor(color);
}

const sf::Sprite& Block::getSprite()
{
	return sprite;
}

void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite);
}