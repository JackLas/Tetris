#ifndef GAME_HPP
#define GAME_HPP

#include "Engine.hpp"

class Game: public Engine
{
private:
public:
	Game(const Game& game) = delete;
	const Game operator=(const Game& game) = delete;

	Game();
	virtual ~Game();

	void handleInput();
	void update(const float deltaTime);
	void render();
};

#endif //GAME_HPP