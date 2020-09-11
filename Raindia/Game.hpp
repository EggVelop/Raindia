#ifndef Game_HPP
#define Game_HPP

#include "State.hpp"

class Game
{
private:

	// Variables

	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	// Initialization Functions

	void initWindow();

public:

	// Constructors / Destructors

	Game();
	virtual ~Game();

	// Functions

	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif