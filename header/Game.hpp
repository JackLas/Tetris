#ifndef GAME_HPP
#define GAME_HPP

#include "Engine.hpp"
#include "GameArea.hpp"
#include "Score.hpp"
#include "Tetramino.hpp"
#include "TetraminoFactory.hpp"
#include "NextTetraminoContainer.hpp"

class Game: public Engine
{
private:
	sf::Texture txBlock;
	sf::Texture txGameAreaFrame;
	sf::Texture txScoreFrame;
	sf::Texture txNextFrame;
	sf::Font font;

	GameArea gameArea;
	Score score;
	NextTetraminoContainer nextTetr;
	TetraminoFactory factory;
	Tetramino *tetramino;
public:
	Game(const Game &game) = delete;
	const Game operator=(const Game &game) = delete;

	Game();
	virtual ~Game();
private:
	void handleInput(const sf::Event &event);
	void update(const float deltaTime);
	void render();

	void checkBorderIntersectionAndPushBack();
	bool checkTetraminoMovingEnd();
	void resetTetramino();
};

#endif //GAME_HPP