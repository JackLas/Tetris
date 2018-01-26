#include "NextTetraminoContainer.hpp"

NextTetraminoContainer::NextTetraminoContainer():
rtxContent(nullptr), content(nullptr), nextTetramino(nullptr)
{
	frame.setColor(sf::Color::Blue);
}

NextTetraminoContainer::~NextTetraminoContainer()
{
	delete content;
	delete rtxContent;
}

void NextTetraminoContainer::setPosition(const sf::Vector2i position)
{
	sf::Vector2f floatPos(static_cast<float>(position.x), static_cast<float>(position.y));
	frame.setPosition(floatPos);
	centerPosition.x = floatPos.x + frame.getGlobalBounds().width/2;
	centerPosition.y = floatPos.y + frame.getGlobalBounds().height/2;
}

void NextTetraminoContainer::setFrame(const sf::Texture &tx)
{
	frame.setTexture(tx);
}

void NextTetraminoContainer::push(Tetramino *tetramino)
{
	nextTetramino = tetramino;
	Tetramino tmpTetramino(*tetramino);
	tmpTetramino.setPositionOffset(sf::Vector2i(0, 0));
	tmpTetramino.setBuildingPosition(sf::Vector2i(0, 0));
	
	sf::Vector2i min(tmpTetramino[0].getBuildingPosition());
	for(unsigned int i = 1; i < tmpTetramino.getNumOfBlocks(); ++i)
	{
		sf::Vector2i cur(tmpTetramino[i].getBuildingPosition());
		if(cur.x < min.x) min.x = cur.x;
		if(cur.y < min.y) min.y = cur.y;
	}
	
	if(min.x < 0) tmpTetramino.setBuildingPosition(sf::Vector2i(-min.x, 0));
	if(min.y < 0) tmpTetramino.setBuildingPosition(sf::Vector2i(0, -min.y));
	tmpTetramino.adaptPixelPosition();

	sf::Vector2i max(tmpTetramino[0].getBuildingPosition());
	for(unsigned int i = 1; i < tmpTetramino.getNumOfBlocks(); ++i)
	{
		sf::Vector2i cur(tmpTetramino[i].getBuildingPosition());
		if(cur.x > max.x) max.x = cur.x;
		if(cur.y > max.y) max.y = cur.y;
	}

	sf::Vector2i textureSize = (tmpTetramino.getBuildingPosition() + max + sf::Vector2i(1, 1))*30;

	delete rtxContent;
	rtxContent = new sf::RenderTexture();
	rtxContent->create(textureSize.x, textureSize.y);
	rtxContent->clear(sf::Color::Transparent);
	rtxContent->draw(tmpTetramino);
	rtxContent->display();
	delete content;
	content = new sf::Sprite();
	content->setTexture(rtxContent->getTexture());
	content->setOrigin(content->getGlobalBounds().width/2, content->getGlobalBounds().height/2);
	content->setPosition(centerPosition);
}

Tetramino* NextTetraminoContainer::pop()
{
	Tetramino* tmp = nextTetramino;
	nextTetramino = nullptr;
	return tmp;
}

void NextTetraminoContainer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(*content, states);
	target.draw(frame, states);
}