#ifndef TETRAMINOFACTORY_HPP
#define TETRAMINOFACTORY_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Tetramino.hpp"

class TetraminoFactory
{
private:
	sf::Texture *txBlock;
	std::vector<sf::Color> colors;
	sf::Vector2f spawnPoint;
public:
	TetraminoFactory(const TetraminoFactory &factory) = delete;
	void operator=(const TetraminoFactory &factory) = delete;

	TetraminoFactory();
	~TetraminoFactory();

	void setBlockTexture(sf::Texture &texture);
	void setSpawnPoint(const sf::Vector2f point);

	Tetramino* nextTetramino();
private:
	void initColors();
};

#endif //TETRAMINOFACTORY_HPP