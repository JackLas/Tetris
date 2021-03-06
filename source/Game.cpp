#include "Game.hpp"
#include "ResourceLoader.hpp"

Game::Game(): 
isGameOver(false),
isPaused(false)
{
	ResourceLoader loader("resources.rp");
	txBlock = loader.loadTexture("block.png");
	txGameAreaFrame = loader.loadTexture("gameAreaFrame.png");
	txScoreFrame = loader.loadTexture("scoreFrame.png");
	txNextFrame = loader.loadTexture("nextFrame.png");
	font = loader.loadFont("font.ttf");

	message.setFont(font);
	message.setPosition(426, 250);
	message.setCharacterSize(20);

	factory.setBlockTexture(txBlock);
	factory.setSpawnPoint(sf::Vector2i(4, 0));

	score.setFrame(txScoreFrame);
	score.setPosition(sf::Vector2i(344, 585));
	score.setFont(font);

	gameArea.setFrame(txGameAreaFrame);
	gameArea.connectScoreUnit(score);

	nextTetr.setFrame(txNextFrame);
	nextTetr.setPosition(sf::Vector2i(344, 15));

	tetramino = factory.nextTetramino();
	nextTetr.push(factory.nextTetramino());
}

Game::~Game()
{
	delete tetramino;
}

void Game::handleInput(const sf::Event &event)
{
	if(event.type == sf::Event::KeyReleased)
	{
		if(event.key.code == sf::Keyboard::Space)
		{
			isPaused = !isPaused;
			if(!isGameOver)
				setMessage(isPaused ? "Pause" : "");
		}
	}	

	if(isPaused) return;

	if(event.type == sf::Event::KeyPressed)
	{
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
	{
		if(event.key.code == sf::Keyboard::Left)
			tetramino->resetMovingLeft();

		if( event.key.code == sf::Keyboard::Right)
			tetramino->resetMovingRight();

		if(event.key.code == sf::Keyboard::Down)
			tetramino->speedDown();
	}
}

void Game::update(const float deltaTime)
{
	if(isPaused) return;

	Block oldTetrBlocks[4];
	for(unsigned int i = 0; i < tetramino->getNumOfBlocks(); ++i)
		oldTetrBlocks[i] = (*tetramino)[i];
	sf::Vector2i oldTetrPos = tetramino->getBuildingPosition();

	tetramino->update(deltaTime);
	checkBorderIntersectionAndPushBack();
	if(checkBlocksIntersection())
	{
		for(unsigned int i = 0; i < tetramino->getNumOfBlocks(); ++i)
			(*tetramino)[i] = oldTetrBlocks[i];
		tetramino->setBuildingPosition(oldTetrPos);
	}
	if(checkTetraminoMovingEnd())
	{
		gameArea.takeBlocksFromTetramino(*tetramino);
		resetTetramino();
	}
	gameArea.update();
	
}

void Game::render()
{
	window.draw(*tetramino);
	window.draw(gameArea);
	window.draw(nextTetr);
	window.draw(score);
	window.draw(message);
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
		tetramino->hardMove(sf::Vector2i(-(max.x % static_cast<int>(gameArea.getNumOfColumns()-1)), 0));
	if(max.y > static_cast<int>(gameArea.getNumOfRows()-1))
		tetramino->hardMove(sf::Vector2i(0, -(max.y % static_cast<int>(gameArea.getNumOfRows()-1))));
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

bool Game::checkBlocksIntersection()
{
	for(unsigned int i = 0; i < tetramino->getNumOfBlocks(); ++i)
	{
		sf::Vector2i absolutePosition = tetramino->getBuildingPosition() + (*tetramino)[i].getBuildingPosition();
		if(!gameArea.isBlockEmpty(absolutePosition.x, absolutePosition.y))
			return true;
	}
	return false;
}	

void Game::resetTetramino()
{
	if(isGameOver)
		return;
	
	delete tetramino;
	tetramino = nextTetr.pop();
	nextTetr.push(factory.nextTetramino());
	if(checkBlocksIntersection())
	{
		isGameOver = true;
		setMessage("Game over!");
	}
}

void Game::setMessage(const std::string &text)
{
	message.setString(text);
	message.setOrigin(message.getGlobalBounds().width/2, 0);
}
