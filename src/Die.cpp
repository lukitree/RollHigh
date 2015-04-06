/*
 * Die.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: eddy
 */

#include "Die.h"
#include <random>
#include <functional>

Die::Die(int size){
	sides = size;
}

int
Die::roll(void){
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, sides-1);

//	for (int i = 0; i < 16; ++i){
//	dist(mt);
//	}

	return dist(mt);
}
