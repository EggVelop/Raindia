#ifndef Game_HPP
#define Game_HPP

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Network.hpp"

class Game
{
private:

	// Variables

	sf::RenderWindow *window;
	sf::Event sfEvent;

	// Initialization Functions

	void initWindow();

public:

	// Constructors / Destructors

	Game();
	virtual ~Game();

	// Functions

	void updateSFMLEvents();
	void update();
	void render();
	void run();
};

#endif