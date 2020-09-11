// Game.cpp

#include "Game.hpp"

// Static Functions

// Initialization Functions

void Game::initWindow() {
	// Creates a SFML Window using options from a window.ini file.

	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Hello World in SFML!");
}

// Constructors / Destructors

Game::Game() {
	this->initWindow();
}

Game::~Game() {
	delete this->window;
}

// Functions

void Game::updateDt() {
	// Updates the dt variable with the time it takes to update and render one frame.

	this->dt = this->dtClock.restart().asSeconds();

	system("cls");
	std::cout << this->dt << std::endl;
}

void Game::updateSFMLEvents() {
	while (this->window->pollEvent(this->sfEvent)) {
		if (this->sfEvent.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::update() {
	// Update all SFML events

	this->updateSFMLEvents();
}

void Game::render() {
	this->window->clear();

	// Render Items

	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}