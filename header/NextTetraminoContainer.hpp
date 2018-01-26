#ifndef NEXTTETRAMINOCONTAINER_HPP
#define NEXTTETRAMINOCONTAINER_HPP

#include <SFML\Graphics.hpp>

#include "Tetramino.hpp"

class NextTetraminoContainer: public sf::Drawable
{
private:
	sf::Sprite frame;
	sf::Vector2f centerPosition;
	sf::RenderTexture *rtxContent;
	sf::Sprite *content;
	Tetramino *nextTetramino;
public:
	NextTetraminoContainer(const NextTetraminoContainer &cont) = delete;
	void operator=(const NextTetraminoContainer &cont) = delete;

	NextTetraminoContainer();
	~NextTetraminoContainer();

	void setPosition(const sf::Vector2i position);
	void setFrame(const sf::Texture &tx);

	void push(Tetramino *tetramino);
	Tetramino* pop();

	void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const;
};

#endif //NEXTTETRAMINOCONTAINER_HPP