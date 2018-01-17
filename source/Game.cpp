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

	gameArea.setFrame(txGameAreaFrame);

	tetramino = factory.nextTetramino();
	tetramino->setBuildingPosition(sf::Vector2f(4, 4));
	tetramino->adaptPixelPosition();
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
		{
			delete tetramino;
			tetramino = factory.nextTetramino();
			tetramino->setBuildingPosition(sf::Vector2f(4, 4));
			tetramino->adaptPixelPosition();
		}

		if(event.key.code == sf::Keyboard::Up)
			tetramino->rotate();

		if(event.key.code == sf::Keyboard::Left)
			tetramino->moveLeft();

		if(event.key.code == sf::Keyboard::Right)
			tetramino->moveRight();
	}
}

void Game::update(const float deltaTime)
{
	tetramino->update();
}

void Game::render()
{
	window.draw(*tetramino);
	window.draw(gameArea);
}