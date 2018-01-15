#include "Tetramino.hpp"

Tetramino::Tetramino(const sf::Texture &texture)
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		blocks[i].setTexture(texture);

	//test, delete in future
	blocks[0].setBuildingPosition(sf::Vector2f(0,0));
	blocks[1].setBuildingPosition(sf::Vector2f(0,1));
	blocks[2].setBuildingPosition(sf::Vector2f(1,0));
	blocks[3].setBuildingPosition(sf::Vector2f(1,1));
	//----------------------
}

Tetramino::Tetramino(const Tetramino &tetramino)
{
}

void Tetramino::operator=(const Tetramino &tetramino)
{
}
Tetramino::~Tetramino()
{
}

void Tetramino::update()
{
	setPixelPosition();
}

void Tetramino::setPositionOffset(const sf::Vector2f position)
{
	offset = position;
}

void Tetramino::setBuildingPosition(const sf::Vector2f position)
{
	buildingPosition = position;
}

void Tetramino::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		target.draw(blocks[i], states);
	}
}

void Tetramino::setPixelPosition()
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		blocks[i].setPixelPosition(sf::Vector2f(
			offset.x + buildingPosition.x*30 + blocks[i].getBuildingPosition().x*30,
			offset.y + buildingPosition.y*30 + blocks[i].getBuildingPosition().y*30));
	}
}