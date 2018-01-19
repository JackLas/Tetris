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
	frame.setPosition(15.f, 15.f);	
	frame.setColor(sf::Color::Blue);

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

bool GameArea::isBlockEmpty(const unsigned int x, const unsigned int y)
{
	return blocks[y][x] == nullptr;
}

void GameArea::takeBlocksFromTetramino(Tetramino &tetramino)
{
	for(unsigned int i = 0; i < tetramino.getNumOfBlocks(); ++i)
	{
		sf::Vector2i absolutePosition = tetramino.getBuildingPosition() + tetramino[i].getBuildingPosition();
		delete blocks[absolutePosition.y][absolutePosition.x];
		blocks[absolutePosition.y][absolutePosition.x] = new sf::Sprite(tetramino[i].getSprite());
	}
}

void GameArea::update()
{
	for(unsigned int i = 0; i < numOfRows; ++i)
	{
		if(isFullLine(i))
		{
			for(unsigned int k = i; k > 1; --k)
			{
				for(unsigned int m = 0; m < numOfColumns; ++m)
				{
					delete blocks[k][m];
					if(blocks[k-1][m] != nullptr)
						blocks[k-1][m]->move(0, 30);
					blocks[k][m] = blocks[k-1][m];
					blocks[k-1][m] = nullptr;
				}
			}
		}
	}
}

void GameArea::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	for(unsigned int i = 0; i < numOfRows; ++i)
		for(unsigned int j = 0; j < numOfColumns; ++j)
			if(blocks[i][j] != nullptr)
				target.draw(*blocks[i][j], states);
	target.draw(frame, states);
}

bool GameArea::isFullLine(const unsigned int line)
{
	for(unsigned int i = 0; i < numOfColumns; ++i)
		if(blocks[line][i] == nullptr)
			return false;
	return true;
}