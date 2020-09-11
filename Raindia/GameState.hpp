#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

class GameState :
	public State {
private:

public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	// Functions
	void endState();

	void update(const float& dt);
	void render(sf::RenderTarget* target = nullptr);
};

#endif