#include "Game.hpp"
#include "ResourceLoader.hpp"

Game::Game()
{
	ResourceLoader loader;
	txBlock = loader.loadTexture("res/block.png");
	txGameAreaFrame = loader.loadTexture("res/gameAreaFrame.png");
	txScoreFrame = loader.loadTexture("res/scoreFrame.png");
	txNextFrame = loader.loadTexture("res/nextFrame.png");

	factory.setBlockTexture(txBlock);
	factory.setSpawnPoint(sf::Vector2i(4, 0));

	gameArea.setFrame(txGameAreaFrame);

	tetramino = factory.nextTetramino();
}

Game::~Game()
{
	delete tetramino;
}

void Game::handleInput(const sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		//test, delete in future
		if(event.key.code == sf::Keyboard::Space)
			resetTetramino();

		//test, delete in future
		if(event.key.code == sf::Keyboard::Return)
		{
			gameArea.takeBlocksFromTetramino(*tetramino);
			resetTetramino();
		}

		if(event.key.code == sf::Keyboard::Up)
			tetramino->rotate();

		if(event.key.code == sf::Keyboard::Left)
			tetramino->moveLeft();

		if(event.key.code == sf::Keyboard::Right)
			tetramino->moveRight();

		if(event.key.code == sf::Keyboard::Down)
			tetramino->speedUp();
	}

	if(event.type == sf::Event::KeyReleased)
		if(event.key.code == sf::Keyboard::Down)
			tetramino->speedDown();
}

void Game::update(const float deltaTime)
{
	tetramino->update(deltaTime);
	checkBorderIntersectionAndPushBack();
	if(checkTetraminoMovingEnd())
	{
		gameArea.takeBlocksFromTetramino(*tetramino);
		resetTetramino();
	}
	
}

void Game::render()
{
	window.draw(*tetramino);
	window.draw(gameArea);
}

void Game::checkBorderIntersectionAndPushBack()
{
	sf::Vector2i min(tetramino->getBuildingPosition() + (*tetramino)[0].getBuildingPosition());
	sf::Vector2i max(min);

	for(unsigned int i = 1; i < tetramino->getNumOfBlocks(); ++i)
	{
		sf::Vector2i cur = tetramino->getBuildingPosition() + (*tetramino)[i].getBuildingPosition();
		if(cur.x > max.x) max.x = cur.x;
		if(cur.x < min.x) min.x = cur.x;
		if(cur.y > max.y) max.y = cur.y;
		if(cur.y < min.y) min.y = cur.y;
	}

	if(min.x < 0) 
		tetramino->hardMove(sf::Vector2i(-min.x, 0));  
	if(min.y < 0) 
		tetramino->hardMove(sf::Vector2i(0, -min.y));
	if(max.x > static_cast<int>(gameArea.getNumOfColumns()-1)) 
		tetramino->hardMove(sf::Vector2i(-((int)max.x % ((int)gameArea.getNumOfColumns()-1)), 0));
	if(max.y > static_cast<int>(gameArea.getNumOfRows()-1))
		tetramino->hardMove(sf::Vector2i(0, -((int)max.y % ((int)gameArea.getNumOfRows()-1))));
}

bool Game::checkTetraminoMovingEnd()
{
	for(unsigned int i = 0; i < tetramino->getNumOfBlocks(); ++i)
	{
		sf::Vector2i absolutePosition = tetramino->getBuildingPosition() + (*tetramino)[i].getBuildingPosition();

		if(absolutePosition.y == static_cast<int>(gameArea.getNumOfRows()-1))
			return true;

		if(!gameArea.isBlockEmpty(absolutePosition.x, absolutePosition.y+1))
			return true;
	}
	return false;
}

void Game::resetTetramino()
{
	delete tetramino;
	tetramino = factory.nextTetramino();
}