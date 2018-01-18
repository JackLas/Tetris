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

	void setModel_O(Tetramino *tetramino);
	void setModel_I(Tetramino *tetramino);
	void setModel_T(Tetramino *tetramino);
	void setModel_S(Tetramino *tetramino);
	void setModel_Z(Tetramino *tetramino);
	void setModel_J(Tetramino *tetramino);
	void setModel_L(Tetramino *tetramino);
};

#endif //TETRAMINOFACTORY_HPP