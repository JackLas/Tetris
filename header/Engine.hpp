#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>

class Engine
{
protected:
	sf::RenderWindow window;
private:
	sf::Clock clock;
public:
	Engine(const Engine &engine) = delete;
	void operator=(const Engine &engine) = delete;

	Engine();
	virtual ~Engine();

	virtual void handleInput() = 0;
	virtual void update(const float deltaTime) = 0;
	virtual void render() = 0;

	void run();
};

#endif //ENGINE_HPP