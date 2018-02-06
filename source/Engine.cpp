#include "Engine.hpp"
#include <ctime>
#include <cstdlib>

Engine::Engine():
window(sf::VideoMode(523, 644), "Tetris", sf::Style::Close),
pauseKey(sf::Keyboard::Escape),
isPause(false)
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

			if(event.type == sf::Event::KeyReleased &&
				event.key.code == pauseKey)
				isPause = !isPause;

			if(!isPause)
				handleInput(event);
		}

		if(!isPause)
			update(deltaTime);

		window.clear();
		render();
		window.display();
	}
}

void Engine::setPauseKey(sf::Keyboard::Key key)
{
	pauseKey = key;
}

bool Engine::getPauseStatus()
{
	return isPause;
}