#include "Engine.hpp"
#include <ctime>
#include <cstdlib>

Engine::Engine():
window(sf::VideoMode(523, 644), "Tetris", sf::Style::Close)
{
	window.setFramerateLimit(60);
	srand(time(NULL));
}

Engine::~Engine()
{
}

void Engine::run()
{
	while(window.isOpen())
	{
		handleInput();
		update(clock.restart().asSeconds());
		render();
	}
}