/*
 * Player.h
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Window.h"
#include <memory>
#include <string>
#include "Roller.h"

class Player {
public:
						Player(void);
	void 				spawn(int loc_y, int loc_x);
	void 				kill(void);
	void				increase_score(void);
	void 				reset_score(void);
	void 				set_name(const char* _name);
	void 				set_input_key(char key);
	void 				set_number(int i);
	bool 				is_stopped(void);
	char 				get_input_key(void);
	void 				stop_on_number(void);
	int 				get_score(void);
	int 				get_number(void);
	std::string 		get_name(void);
	void 				reset(void);

private:
	void 				display_number(void);

	char 				player_key;
	int					number;
	int 				score;
	Window				window;
	std::string 		name;
	bool 				stopped;
	int 				win_height;
	int 				win_width;
};

#endif /* PLAYER_H_ */
