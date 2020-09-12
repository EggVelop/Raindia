#ifndef STATE_HPP
#define STATE_HPP

#include "Entity.hpp"

class State {
private:

protected:
	sf::RenderWindow* window;
	std::map<std::string, int>* supportedKeys;
	std::map<std::string, int> keybinds;
	bool quit;

	// Resources

	std::vector<sf::Texture> textures;

	// Protected Functions

	virtual void initKeybinds() = 0;
public:
	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
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