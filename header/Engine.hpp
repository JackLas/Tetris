#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SFML/Graphics.hpp>

class Engine
{
protected:
	sf::RenderWindow window;
private:
	sf::Keyboard::Key pauseKey;
	bool isPause;
	sf::Clock clock;
public:
	Engine(const Engine &engine) = delete;
	void operator=(const Engine &engine) = delete;

	Engine();
	virtual ~Engine();
	
	void run();
protected:
	virtual void handleInput(const sf::Event &event) = 0;
	virtual void update(const float deltaTime) = 0;
	virtual void render() = 0;
	void setPauseKey(sf::Keyboard::Key key);
};

#endif //ENGINE_HPP