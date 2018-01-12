#include "GameArea.hpp"

GameArea::GameArea(const sf::Texture &txFrame)
{
	frame.setTexture(txFrame);
	frame.setPosition(sf::Vector2f(15, 15));
}

GameArea::GameArea()
{
	frame.setPosition(sf::Vector2f(15, 15));
}

GameArea::~GameArea()
{
}

void GameArea::setFrame(const sf::Texture &txFrame)
{
	frame.setTexture(txFrame);
}

void GameArea::update()
{
}

void GameArea::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(frame, states);
}