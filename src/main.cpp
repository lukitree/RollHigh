
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
#include "Window.h"

int main(void){
//	initscr();
//	refresh();
//	Window win;
//	win.create("test", 'x', 5, 9, 3, 35);
//	win.print_number(2);
//	getch();
//	endwin();

	Game game;
	game.init();
	game.run();
	return 0;
}
