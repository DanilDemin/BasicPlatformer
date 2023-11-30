#pragma once

#include "stdafx.h"
#include "Player.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;

	Player* player;

	//Private functions
	void initWindow();
	void initPlayer();

public:
	//Con/Des
	Game();
	virtual ~Game();

	//Functions
	void pollingEvents();
	void updatePlayer();
	void update();
	

	void renderPlayer();
	void render();
	

	const sf::RenderWindow& getWindow() const;

};

