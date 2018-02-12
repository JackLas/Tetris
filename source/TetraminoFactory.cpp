#include "TetraminoFactory.hpp"

TetraminoFactory::TetraminoFactory()
{
	spawnPoint.x = 0;
	spawnPoint.y = 0;
	initColors();
}

TetraminoFactory::~TetraminoFactory()
{
}

void TetraminoFactory::setBlockTexture(sf::Texture &texture)
{
	txBlock = &texture;
}

void TetraminoFactory::setSpawnPoint(const sf::Vector2i &point)
{
	spawnPoint = point;
}

Tetramino* TetraminoFactory::nextTetramino()
{
	Tetramino *tetramino = new Tetramino(*txBlock);
	tetramino->setColor(colors[rand()%colors.size()]);
	tetramino->setPositionOffset(sf::Vector2i(15+7, 15+7));
	tetramino->setFallingSpeed(2.f);
	tetramino->setMovingSpeed(7.f);
	tetramino->setBuildingPosition(spawnPoint);
	switch(rand()%7)
	{
		case 0:
			setModel_O(tetramino);
			break;
		case 1:
			setModel_I(tetramino);
			break;
		case 2:
			setModel_T(tetramino);
			break;
		case 3: 
			setModel_S(tetramino);
			break;
		case 4:
			setModel_Z(tetramino);
			break;
		case 5:
			setModel_J(tetramino);
			break;
		case 6: 
			setModel_L(tetramino);
			break;
	}
	tetramino->adaptPixelPosition();
	return tetramino;
}

void TetraminoFactory::initColors()
{
	colors.push_back(sf::Color::Red);
	colors.push_back(sf::Color::Green);
	colors.push_back(sf::Color::Blue);
	colors.push_back(sf::Color::Yellow);
	colors.push_back(sf::Color::Magenta);
	colors.push_back(sf::Color::Cyan);
	colors.push_back(sf::Color(255, 165, 0, 255)); //orange
}

void TetraminoFactory::setModel_O(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(0, 1), sf::Vector2i(1, 0), sf::Vector2i(1, 1));
}

void TetraminoFactory::setModel_I(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(3, 0));
}

void TetraminoFactory::setModel_T(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(1, 1));
}

void TetraminoFactory::setModel_S(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(-1, 0), sf::Vector2i(-1, 1), sf::Vector2i(-2, 1));
}

void TetraminoFactory::setModel_Z(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(1, 1), sf::Vector2i(2, 1));
}

void TetraminoFactory::setModel_J(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(2, 1));
}

void TetraminoFactory::setModel_L(Tetramino *tetramino)
{
	tetramino->setModel(sf::Vector2i(0, 0), sf::Vector2i(1, 0), sf::Vector2i(2, 0), sf::Vector2i(0, 1));
}