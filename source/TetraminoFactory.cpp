#include "TetraminoFactory.hpp"

TetraminoFactory::TetraminoFactory()
{
	initColors();
}

TetraminoFactory::~TetraminoFactory()
{
}

void TetraminoFactory::setBlockTexture(sf::Texture &texture)
{
	txBlock = &texture;
}

void TetraminoFactory::setSpawnPoint(const sf::Vector2f point)
{
	spawnPoint = point;
}

Tetramino* TetraminoFactory::nextTetramino()
{
	Tetramino *tetramino = new Tetramino(*txBlock);
	tetramino->setColor(colors[rand()%colors.size()]);
	tetramino->setPositionOffset(sf::Vector2f(15+7, 15+7));
	tetramino->setBuildingPosition(spawnPoint);
	switch(rand()%7)
	{
		case 0: //O
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(0, 1), 
								sf::Vector2f(1, 0), 
								sf::Vector2f(1, 1));
			break;
		case 1: //I
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(1, 0), 
								sf::Vector2f(2, 0), 
								sf::Vector2f(3, 0));
			break;
		case 2: //S
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(-1, 0), 
								sf::Vector2f(-1, 1), 
								sf::Vector2f(-2, 1));
			break;
		case 3: //Z
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(1, 0), 
								sf::Vector2f(1, 1), 
								sf::Vector2f(2, 1));
			break;
		case 4: //T
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(1, 0), 
								sf::Vector2f(2, 0), 
								sf::Vector2f(1, 1));
			break;
		case 5: //J
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(1, 0), 
								sf::Vector2f(2, 0), 
								sf::Vector2f(2, 1));
			break;
		case 6: //L
			tetramino->setModel(sf::Vector2f(0, 0), 
								sf::Vector2f(1, 0), 
								sf::Vector2f(2, 0), 
								sf::Vector2f(0, 1));
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
}