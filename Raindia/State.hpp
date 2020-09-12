#ifndef STATE_HPP
#define STATE_HPP

#include "Entity.hpp"

class State {
private:

protected:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;
public:
	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;

	// Functions

	virtual void checkForQuit();

	virtual void endState() = 0;

	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

#endif
#pragma once