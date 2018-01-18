#include "GameArea.hpp"

GameArea::GameArea(const sf::Texture &txFrame)
{
	frame.setTexture(txFrame);
	init();
}

GameArea::GameArea()
{
	init();
}

void GameArea::init()
{
	frame.setPosition(sf::Vector2f(15, 15));	
	frame.setColor(sf::Color(0, 0, 255, 255));

	for(unsigned int i = 0; i < numOfRows; ++i)
		for(unsigned int j = 0; j < numOfColumns; ++j)
			blocks[i][j] = nullptr;
}

GameArea::~GameArea()
{
	for(unsigned int i = 0; i < numOfRows; ++i)
		for(unsigned int j = 0; j < numOfColumns; ++j)
			delete blocks[i][j];
}

void GameArea::setFrame(const sf::Texture &txFrame)
{
	frame.setTexture(txFrame);
}

unsigned int GameArea::getNumOfColumns()
{
	return numOfColumns;
}

unsigned int GameArea::getNumOfRows()
{
	return numOfRows;
}

void GameArea::takeBlocksFromTetramino(Tetramino &tetramino)
{
	for(unsigned int i = 0; i < tetramino.getNumOfBlocks(); ++i)
	{
		sf::Vector2f absolutePosition = tetramino.getBuildingPosition() + tetramino[i].getBuildingPosition();
		blocks[(int)absolutePosition.y][(int)absolutePosition.x] = new sf::Sprite(tetramino[i].getSprite());
	}
}

void GameArea::update()
{
}

void GameArea::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < numOfRows; ++i)
		for(unsigned int j = 0; j < numOfColumns; ++j)
			if(blocks[i][j] != nullptr)
				target.draw(*blocks[i][j], states);
	target.draw(frame, states);
}