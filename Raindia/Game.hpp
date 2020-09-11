#ifndef Game_HPP
#define Game_HPP

#include "GameState.hpp"

class Game
{
private:

	// Variables

	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	// Initialization Functions

	void initWindow();
	void initStates();

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