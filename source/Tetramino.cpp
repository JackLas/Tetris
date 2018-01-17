#include "Tetramino.hpp"

Tetramino::Tetramino(const sf::Texture &texture)
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		blocks[i].setTexture(texture);

	buildingPosition.x = 0;
	buildingPosition.y = 0;
	moveValueX = 0;
	isRotate = false;
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


void Tetramino::setPositionOffset(const sf::Vector2f position)
{
	offset = position;
}

void Tetramino::setBuildingPosition(const sf::Vector2f position)
{
	buildingPosition = position;
}

void Tetramino::setModel(sf::Vector2f pos0, sf::Vector2f pos1, sf::Vector2f pos2, sf::Vector2f pos3)
{
	blocks[0].setBuildingPosition(pos0);
	blocks[1].setBuildingPosition(pos1);
	blocks[2].setBuildingPosition(pos2);
	blocks[3].setBuildingPosition(pos3);
}

void Tetramino::adaptPixelPosition()
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		//30 - size of block...bad practice
		blocks[i].setPixelPosition(sf::Vector2f(
			offset.x + buildingPosition.x*30 + blocks[i].getBuildingPosition().x*30,
			offset.y + buildingPosition.y*30 + blocks[i].getBuildingPosition().y*30));
	}
}

void Tetramino::setColor(const sf::Color color)
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		blocks[i].setColor(color);
}

void Tetramino::moveLeft()
{
	moveValueX = -1;
}

void Tetramino::moveRight()
{
	moveValueX = 1;
}

void Tetramino::rotate()
{
	isRotate = true;
}

void Tetramino::update()
{
	bool isChanged = false;

	if(moveValueX != 0)
	{
		moveAction();
		isChanged = true;
		moveValueX = 0;
	}

	if(isRotate)
	{
		rotateAction();
		isChanged = true;
		isRotate = false;
	}

	if(isChanged)
		adaptPixelPosition();

}

void Tetramino::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		target.draw(blocks[i], states);
}

void Tetramino::rotateAction()
{
	sf::Vector2f pivot = blocks[1].getBuildingPosition(); //center of rotation
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		sf::Vector2f tmp;
		tmp.x = blocks[i].getBuildingPosition().y - pivot.y;
		tmp.y = blocks[i].getBuildingPosition().x - pivot.x;
		blocks[i].setBuildingPosition(sf::Vector2f(
			pivot.x - tmp.x, 
			pivot.y + tmp.y)); 
	}
}

void Tetramino::moveAction()
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		sf::Vector2f tmp = blocks[i].getBuildingPosition();
		tmp.x += moveValueX;
		blocks[i].setBuildingPosition(tmp);
	}
}