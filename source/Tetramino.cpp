#include "Tetramino.hpp"

Tetramino::Tetramino(const sf::Texture &texture)
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		blocks[i].setTexture(texture);

	buildingPosition.x = 0.f;
	buildingPosition.y = 0.f;
	moveValueX = 0.f;
	elapsedMovingTime = 0.f;
	elapsedFallingTime = 0.f;
	fallingSpeed = 0.f;
	movingSpeed = 0.f;
	movingStepTime = 0.f;
	isRotate = false;
	isAccelerate = false;
}

Tetramino::Tetramino(const Tetramino &tetramino)
{
	*this = tetramino;
}

void Tetramino::operator=(const Tetramino &tetramino)
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		blocks[i] = tetramino.blocks[i];
	offset = tetramino.offset;
	buildingPosition = tetramino.buildingPosition;
	fallingSpeed = tetramino.fallingSpeed;
	movingSpeed = tetramino.movingSpeed;
	movingStepTime = tetramino.movingStepTime;
	elapsedMovingTime = tetramino.elapsedMovingTime;
	elapsedFallingTime = tetramino.elapsedFallingTime;
	moveValueX = tetramino.moveValueX;
	isRotate = tetramino.isRotate;
	isAccelerate = tetramino.isAccelerate;
}

Block& Tetramino::operator[](const unsigned int index)
{
	return blocks[index];
}

Tetramino::~Tetramino()
{
}

void Tetramino::setPositionOffset(const sf::Vector2i position)
{
	offset = position;
}

void Tetramino::setBuildingPosition(const sf::Vector2i position)
{
	buildingPosition = position;
}

sf::Vector2i Tetramino::getBuildingPosition() const 
{
	return buildingPosition;
}

void Tetramino::setModel(	const sf::Vector2i pos0, 
							const sf::Vector2i pos1, 
							const sf::Vector2i pos2, 
							const sf::Vector2i pos3)
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
		blocks[i].setPixelPosition(sf::Vector2i(
			offset.x + buildingPosition.x*30 + blocks[i].getBuildingPosition().x*30,
			offset.y + buildingPosition.y*30 + blocks[i].getBuildingPosition().y*30));
	}
}

void Tetramino::setColor(const sf::Color color)
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		blocks[i].setColor(color);
}

void Tetramino::setFallingSpeed(const float value)
{
	fallingSpeed = value;
}

void Tetramino::setMovingSpeed(const float value)
{
	movingSpeed = value;
}

unsigned int Tetramino::getNumOfBlocks() const
{
	return numOfBlocks;
}

void Tetramino::moveLeft()
{
	if(moveValueX == 0)
		moveValueX = -1;
}

void Tetramino::moveRight()
{
	if(moveValueX == 0)
		moveValueX = 1;
}

void Tetramino::resetMovingLeft()
{
	if(moveValueX == -1)
		resetMoving();

}

void Tetramino::resetMovingRight()
{
	if(moveValueX == 1)
		resetMoving();
}

void Tetramino::rotate()
{
	isRotate = true;
}

void Tetramino::speedUp()
{
	isAccelerate = true;
}

void Tetramino::speedDown()
{
	isAccelerate = false;
}

void Tetramino::update(const float deltaTime)
{
	bool isChanged = false;
	elapsedFallingTime += deltaTime;
	if(moveValueX != 0)
	{
		elapsedMovingTime += deltaTime;
		if(elapsedMovingTime >= movingStepTime)
		{
			moveAction();
			elapsedMovingTime -= movingStepTime;
			movingStepTime = 1/movingSpeed;
		}
		isChanged = true;
	}

	if(isRotate)
	{
		rotateAction();
		isChanged = true;
		isRotate = false;
	}

	int speedRate = isAccelerate ? 4 : 1;
	if(elapsedFallingTime >= 1/fallingSpeed/speedRate)
	{
		++buildingPosition.y;
		elapsedFallingTime = 0;
		isChanged = true;
	}

	if(isChanged)
		adaptPixelPosition();
}

void Tetramino::hardMove(const sf::Vector2i step)
{
	buildingPosition += step;
	adaptPixelPosition();
}

void Tetramino::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
		target.draw(blocks[i], states);
}

void Tetramino::rotateAction()
{
	sf::Vector2i pivot = blocks[1].getBuildingPosition(); //center of rotation
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		sf::Vector2i tmp;
		tmp.x = blocks[i].getBuildingPosition().y - pivot.y;
		tmp.y = blocks[i].getBuildingPosition().x - pivot.x;
		blocks[i].setBuildingPosition(sf::Vector2i(
			pivot.x - tmp.x, 
			pivot.y + tmp.y)); 
	}
}

void Tetramino::moveAction()
{
	for(unsigned int i = 0; i < numOfBlocks; ++i)
	{
		sf::Vector2i tmp = blocks[i].getBuildingPosition();
		tmp.x += moveValueX;
		blocks[i].setBuildingPosition(tmp);
	}
}

void Tetramino::resetMoving()
{
	moveValueX = 0;
	elapsedMovingTime = 0.f;
	movingStepTime = 0.f;
}