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

class Player {
public:
						Player(unsigned int pnum);
	void 				spawn(int loc_y, int loc_x);
	void				increase_score(void);
	void 				reset_score(void);
	void 				set_name(const char* _name);

private:
	unsigned int		number;
	Window				window;
	unsigned int 		score;
	std::string 		name;
};

#endif /* PLAYER_H_ */