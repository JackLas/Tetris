#ifndef GAMEAREA_HPP
#define GAMEAREA_HPP

#include <SFML/Graphics.hpp>

class GameArea: public sf::Drawable
{
private:
	sf::Sprite frame;
public:
	GameArea(const GameArea &area) = delete;
	void operator=(const GameArea &area) = delete;

	GameArea(const sf::Texture &txFrame);
	GameArea();
	~GameArea();

	void setFrame(const sf::Texture &txFrame);

	void update();
	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
};

#endif //GAMEAREA_HPP