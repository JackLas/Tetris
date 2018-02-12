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
		float deltaTime = clock.restart().asSeconds();
		
		sf::Event event;
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
				window.close();

			handleInput(event);
		}

		update(deltaTime);

		window.clear();
		render();
		window.display();
	}
}