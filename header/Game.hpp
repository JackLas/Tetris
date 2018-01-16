#ifndef GAME_HPP
#define GAME_HPP

#include "Engine.hpp"
#include "GameArea.hpp"
#include "Tetramino.hpp"
#include "TetraminoFactory.hpp"

class Game: public Engine
{
private:
	sf::Texture txBlock;
	sf::Texture txGameAreaFrame;
	sf::Texture txScoreFrame;
	sf::Texture txNextFrame;

	GameArea gameArea;
	TetraminoFactory factory;
	Tetramino *tetramino;
public:
	Game(const Game &game) = delete;
	const Game operator=(const Game &game) = delete;

	Game();
	virtual ~Game();

	void handleInput(const sf::Event event);
	void update(const float deltaTime);
	void render();
};

#endif //GAME_HPP