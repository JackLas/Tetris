#include "Score.hpp"
#include <sstream>

Score::Score(): score(0)
{
	frame.setColor(sf::Color::Blue);
	text.setCharacterSize(26);
	adaptScoreToText();
}

Score::~Score()
{
}

void Score::setPosition(const sf::Vector2i position)
{
	frame.setPosition(position.x, position.y);
	adaptTextPosition();
}

void Score::setFrame(const sf::Texture &texture)
{
	frame.setTexture(texture);
}

void Score::setFont(const sf::Font &font)
{
	text.setFont(font);
	adaptTextPosition();
}

void Score::addPoints(const int points)
{
	score += points;
	if(score > 99999) score = 0;
	adaptScoreToText();
	adaptTextPosition();
}

void Score::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(frame, states);
	target.draw(text, states);
}

void Score::adaptTextPosition()
{
	text.setOrigin(text.getGlobalBounds().width/2, text.getGlobalBounds().height/2);
	text.setPosition(	frame.getPosition().x + frame.getGlobalBounds().width/2, 
						frame.getPosition().y + text.getGlobalBounds().height/2+9);	
}


void Score::adaptScoreToText()
{
	std::ostringstream stream;
	stream << score;
	text.setString(stream.str());
}
