/*
 * Player.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#include "Player.h"

Player::Player(unsigned int pnum){
	number = pnum;
	score = 0;
	name = "Empty";
}

void
Player::spawn(int loc_y, int loc_x){
	window.create(name, 5, 10, loc_y, loc_x);
}

void
Player::increase_score(void){
	++score;
}

void
Player::reset_score(void){
	score = 0;
}

void
Player::set_name(const char* _name){
	name = _name;
}
