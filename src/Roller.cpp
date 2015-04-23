/*
 * Roller.cpp
 *
 *  Created on: Apr 6, 2015
 *      Author: eddy
 */

#include <chrono>

#include "Roller.h"

void
Roller::start_cycle(int size){
	sides = size;
	number = 0;
	keep_cycling = true;

	std::thread t {std::bind(&Roller::cycle, this)};
	t.detach();
}

void
Roller::stop_cycle(void){
	keep_cycling = false;
}

void Roller::cycle(void){
	int sleep_time = 10;
	while(keep_cycling)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(sleep_time));
		if(number < sides-1)
			++number;
		else
			number = 0;
	}
}

int Roller::get_number(void){
	return number;
}
