/*
 * Window.cpp
 *
 *  Created on: Apr 2, 2015
 *      Author: eddy
 */

#include "Window.h"
#include <string>
#include <iostream>

void
Window::create(std::string title, 
				char ch, 
				int win_height, 
				int win_width, 
				int win_pos_y, 
				int win_pos_x){
	height = win_height;
	width = win_width;
	window = newwin (win_height, win_width, win_pos_y, win_pos_x);
	box(window, 0, 0);
	wprintw(window, title.c_str());
	wmove(window, height-2, width-2);
	waddch(window, ch);
	wrefresh(window);
}

void
Window::print_number(int i){
	std::string c = std::to_string(i);
	mvwprintw(window, (height/2), (width/2) , c.c_str());
	wrefresh(window);
}
