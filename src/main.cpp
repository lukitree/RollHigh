
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
#include "Die.h"

int main(void){
	Die die(10);
	for(int q = 0; q < 10; ++q){
		std::cout << die.roll() << ' ';
	}
	std::cout << std::endl;
	//Game game;
	//game.run();
	return 0;
}
