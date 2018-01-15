#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <SFML\Graphics.hpp>
#include "Block.hpp"

class Tetramino: public sf::Drawable
{
private:
	static const unsigned int numOfBlocks = 4;
	Block blocks[numOfBlocks];
	sf::Vector2f offset;
	sf::Vector2f buildingPosition;
private:
	void setPixelPosition();
public:
	Tetramino(const sf::Texture &texture);
	Tetramino(const Tetramino &tetramino);
	void operator=(const Tetramino &tetramino);
	~Tetramino();

	void update();
	void setPositionOffset(const sf::Vector2f position);
	void setBuildingPosition(const sf::Vector2f position);
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const; 
};

#endif //TETRAMINO_HPP