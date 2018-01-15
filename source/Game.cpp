#include "Game.hpp"
#include "ResourceLoader.hpp"

Game::Game()
{
	ResourceLoader loader;
	txBlock = loader.loadTexture("res/block.png");
	txGameAreaFrame = loader.loadTexture("res/gameAreaFrame.png");
	txScoreFrame = loader.loadTexture("res/scoreFrame.png");
	txNextFrame = loader.loadTexture("res/nextFrame.png");

	gameArea.setFrame(txGameAreaFrame);
	tetramino = new Tetramino(txBlock);
	tetramino->setPositionOffset(sf::Vector2f(15+7, 15+7));
	tetramino->setBuildingPosition(sf::Vector2f(0,0));
}

Game::~Game()
{
	delete tetramino;
}

void Game::handleInput(const sf::Event event)
{
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