#ifndef GAMEAREA_HPP
#define GAMEAREA_HPP

#include <SFML/Graphics.hpp>
#include "Tetramino.hpp"

class GameArea: public sf::Drawable
{
private:
	static const unsigned int numOfColumns = 10;
	static const unsigned int numOfRows = 20;
	sf::Sprite frame;
	sf::Sprite *blocks[numOfRows][numOfColumns];
public:
	GameArea(const GameArea &area) = delete;
	void operator=(const GameArea &area) = delete;

	GameArea(const sf::Texture &txFrame);
	GameArea();
	~GameArea();

	void setFrame(const sf::Texture &txFrame);
	
	unsigned int getNumOfColumns();
	unsigned int getNumOfRows();

	void takeBlocksFromTetramino(Tetramino &tetramino);
	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
private:
	void init();
};

#endif //GAMEAREA_HPP