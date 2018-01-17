#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <SFML\Graphics.hpp>
#include <array>

#include "Block.hpp"

class Tetramino: public sf::Drawable
{
private:
	static const unsigned int numOfBlocks = 4;
	Block blocks[numOfBlocks];
	sf::Vector2f offset;
	sf::Vector2f buildingPosition;

	float moveValueX;
	bool isRotate;

public:
	Tetramino(const sf::Texture &texture);
	Tetramino(const Tetramino &tetramino);
	void operator=(const Tetramino &tetramino);
	~Tetramino();

	void setPositionOffset(const sf::Vector2f position);
	void setBuildingPosition(const sf::Vector2f position);
	void setModel(sf::Vector2f pos0, sf::Vector2f pos1, sf::Vector2f pos2, sf::Vector2f pos3);
	void adaptPixelPosition();
	void setColor(const sf::Color color); 

	void moveLeft();
	void moveRight();
	void rotate();
	void update();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
private:
	void rotateAction();
	void moveAction();
};

#endif //TETRAMINO_HPP