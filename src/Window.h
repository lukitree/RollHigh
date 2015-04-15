/*
 * Window.h
 *
 *  Created on: Apr 2, 2015
 *      Author: eddy
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <ncurses.h>
#include <string>

class Window {
public:
	void 				create(std::string title, 
								char ch,
								int win_height,
								int win_width,
								int win_pos_y,
								int win_pos_x);
	void 				print_number(int c);

private:
	WINDOW*				window;	
	unsigned int		height;
	unsigned int 		width;
};

#endif /* WINDOW_H_ */
