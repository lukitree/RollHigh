/*
 * Window.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: eddy
 */

#include "Window.h"

void
Window::create(std::string title, int win_height, int win_width, int win_pos_y, int win_pos_x){
	height = win_height;
	width = win_width;
	window = newwin (win_height, win_width, win_pos_y, win_pos_x);
	box(window, 0, 0);
	wprintw(window, title.c_str());
	wrefresh(window);
}

void
Window::print_number(char c){
	mvwaddch(window, (height/2), (width/2), c);
}
