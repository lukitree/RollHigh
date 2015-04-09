
/*
 * main.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#include <iostream>
#include <ncurses.h>
#include "Game.h"

//testing only
#include "Roller.h"

int main(void){
	Game game;
	game.init();
	game.run();
	return 0;
}
