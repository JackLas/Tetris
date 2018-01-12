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

void Game::handleInput()
{
	sf::Event event;
	while(window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
			window.close();
	}
}

void Game::update(const float deltaTime)
{
}

void Game::render()
{
	window.clear();
		window.draw(gameArea);
	window.display();
}