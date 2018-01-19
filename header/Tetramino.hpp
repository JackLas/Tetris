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
	sf::Vector2i offset;
	sf::Vector2i buildingPosition;
	float speed; //number of steps down per second
	float elapsedTime;

	int moveValueX;
	bool isRotate;
	bool isAccelerate;

public:
	Tetramino(const sf::Texture &texture);
	Tetramino(const Tetramino &tetramino);
	void operator=(const Tetramino &tetramino);
	Block& operator[](const unsigned int index);
	~Tetramino();

	void setPositionOffset(const sf::Vector2i position);
	void setBuildingPosition(const sf::Vector2i position);
	sf::Vector2i getBuildingPosition() const;
	void setModel(	const sf::Vector2i pos0, 
					const sf::Vector2i pos1, 
					const sf::Vector2i pos2, 
					const sf::Vector2i pos3);
	void adaptPixelPosition();
	void setColor(const sf::Color color);
	void setSpeed(const float value);
	unsigned int getNumOfBlocks() const; 

	void moveLeft();
	void moveRight();
	void rotate();
	void speedUp();
	void speedDown();
	void update(const float deltaTime);

	void hardMove(const sf::Vector2i step);

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
private:
	void rotateAction();
	void moveAction();
};

#endif //TETRAMINO_HPP