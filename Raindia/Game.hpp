#ifndef Game_HPP
#define Game_HPP

#include "GameState.hpp"

class Game {
private:

	// Variables

	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	// Initialization Functions

	void initWindow();
	void initKeys();
	void initStates();

public:

	// Constructors / Destructors

	Game();
	virtual ~Game();

	// Functions

	void endApplication();
	void updateDt();
	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif