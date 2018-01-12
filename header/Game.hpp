#ifndef GAME_HPP
#define GAME_HPP

#include "Engine.hpp"
#include "GameArea.hpp"

class Game: public Engine
{
private:
	sf::Texture txBlock;
	sf::Texture txGameAreaFrame;
	sf::Texture txScoreFrame;
	sf::Texture txNextFrame;

	GameArea gameArea;
public:
	Game(const Game &game) = delete;
	const Game operator=(const Game &game) = delete;

	Game();
	virtual ~Game();

	void handleInput();
	void update(const float deltaTime);
	void render();
};

#endif //GAME_HPP