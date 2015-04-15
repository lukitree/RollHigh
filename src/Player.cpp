/*
 * Player.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#include "Player.h"
#include <iostream>

Player::Player(){
	score = 0;
	name = "Empty";
	player_key = ' ';
	stopped = false;
	number = -1;

	win_height = 5;
	win_width = 9;
}

void
Player::spawn(int loc_y, int loc_x){
	window.create(name, player_key, win_height, win_width, loc_y, loc_x);
//	window.print_input_key(player_key);
}

void
Player::kill(void){
	std::cerr << "Not implemented yet!" << std::endl;
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

void
Player::set_input_key(char key){
	player_key = key;	
}

void
Player::set_number(int i){
	if(!stopped)
	{
		number = i;
	}
	display_number();
}

void
Player::display_number(void){
		window.print_number(number);
}

bool
Player::is_stopped(void){
	return stopped;
}

char
Player::get_input_key(void){
	return player_key;
}

void
Player::stop_on_number(void){
	stopped = true;
}

int
Player::get_number(void){
	return number;
}

int
Player::get_score(void){
	return score;
}

void
Player::reset(void){
	stopped = false;
}

std::string
Player::get_name(void){
	return name;
}
