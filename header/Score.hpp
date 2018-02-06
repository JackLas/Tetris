#ifndef SCORE_HPP
#define SCORE_HPP

#include <SFML/Graphics.hpp>

class Score: public sf::Drawable
{
private:
	sf::Sprite frame;
	sf::Text text;
	unsigned int score;
public:
	Score(const Score &score) = delete;
	void operator=(const Score &score) = delete;

	Score();
	~Score();
	void setPosition(const sf::Vector2i position);
	void setFrame(const sf::Texture &texture);
	void setFont(const sf::Font &font);

	void addPoints(const int points);

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
private:
	void adaptTextPosition();
	void adaptScoreToText();
};

#endif //SCORE_HPP