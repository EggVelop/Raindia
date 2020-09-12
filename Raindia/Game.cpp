// Game.cpp

#include "Game.hpp"

// Static Functions

// Initialization Functions

void Game::initWindow() {
	// Creates a SFML Window using options from a window.ini file.

	std::ifstream ifs("Config/window.ini");

	// Defaults

	std::string title = "None";
	sf::VideoMode window_bounds(800, 600);
	unsigned framerate_limit = 120;
	bool vertical_sync_enabled = false;

	if (ifs.is_open()) {
		std::getline(ifs, title);
		ifs >> window_bounds.width >> window_bounds.height;
		ifs >> framerate_limit;
		ifs >> vertical_sync_enabled;
	}

	ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::initKeys() {
	this->supportedKeys.emplace("Escape", sf::Keyboard::Key::Escape);
	this->supportedKeys.emplace("A", sf::Keyboard::Key::A);
	this->supportedKeys.emplace("D", sf::Keyboard::Key::D);
	this->supportedKeys.emplace("W", sf::Keyboard::Key::W);
	this->supportedKeys.emplace("S", sf::Keyboard::Key::S);
}

void Game::initStates() {
	this->states.push(new GameState(this->window, &this->supportedKeys));
}

// Constructors / Destructors

Game::Game() {
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() {
	delete this->window;

	while (this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}

// Functions

void Game::endApplication() {
	std::cout << "Ending application" << std::endl;
}

void Game::updateDt() {
	// Updates the dt variable with the time it takes to update and render one frame.

	this->dt = this->dtClock.restart().asSeconds();
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

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	// Application End
	} else {
		this->endApplication();
		this->window->close();
	}
}

void Game::render() {
	this->window->clear();

	// Render Items

	if (!this->states.empty())
		this->states.top()->render(this->window);

	this->window->display();
}

void Game::run() {
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

// hezigonic was here