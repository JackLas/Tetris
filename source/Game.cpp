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
}

Game::~Game()
{
}

void Game::handleInput(const sf::Event event)
{
}

void Game::update(const float deltaTime)
{
}

void Game::render()
{
	window.draw(gameArea);
}