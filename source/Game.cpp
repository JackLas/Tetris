#include "Game.hpp"

Game::Game()
{
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
		//draw
	window.display();
}