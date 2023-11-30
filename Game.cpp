#include "game.h"

//Private functions
void Game::initWindow()
{
	window.create(sf::VideoMode(1920, 1080), "Platformer",
		sf::Style::Default);
	window.setFramerateLimit(90);
}

void Game::initPlayer()
{
	player = new Player();
}

//Con/Des
Game::Game()
{
	initWindow();
	initPlayer();
}

Game::~Game()
{
	delete player;
}

void Game::pollingEvents()
{	
	//Polling window events
	while (window.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
		{
			window.close();
		}
		else if (ev.type == sf::Event::KeyReleased &&
			ev.key.code == sf::Keyboard::Escape)
		{
			window.close();
		}
	}
}

void Game::updatePlayer()
{
	player->update();
}

void Game::update()
{
	pollingEvents();
	updatePlayer();
}


void Game::renderPlayer()
{
	player->render(window);
}

void Game::render()
{
	window.clear();

	//Render game
	renderPlayer();

	window.display();
}

//Functions
const sf::RenderWindow& Game::getWindow() const
{
	return window;
}
