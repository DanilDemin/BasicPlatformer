 
#include "Game.h"

void main(int argc, char** argv[]) {

	srand(static_cast<unsigned>(time(0)));


	Game game;

	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}
}

