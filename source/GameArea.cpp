#include "GameArea.hpp"

GameArea::GameArea(const sf::Texture &txFrame)
{
	frame.setTexture(txFrame);
	init();
}

GameArea::GameArea()
{
	init();
}

void GameArea::init()
{
	frame.setPosition(sf::Vector2f(15, 15));	
	frame.setColor(sf::Color(0, 0, 255, 255));
}

GameArea::~GameArea()
{
}

void GameArea::setFrame(const sf::Texture &txFrame)
{
	frame.setTexture(txFrame);
}

unsigned int GameArea::getNumOfColumns()
{
	return numOfColumns;
}

unsigned int GameArea::getNumOfRows()
{
	return numOfRows;
}

void GameArea::update()
{
}

void GameArea::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(frame, states);
}