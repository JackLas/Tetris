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
public:
	TetraminoFactory(const TetraminoFactory &factory) = delete;
	void operator=(const TetraminoFactory &factory) = delete;

	TetraminoFactory();
	TetraminoFactory(sf::Texture &texture);
	~TetraminoFactory();

	void setBlockTexture(sf::Texture &texture);

	Tetramino* nextTetramino();
private:
	void initColors();
};

#endif //TETRAMINOFACTORY_HPP