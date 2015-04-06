/*
 * Die.h
 *
 *  Created on: Apr 5, 2015
 *      Author: eddy
 */

#ifndef DIE_H_
#define DIE_H_

class Die{
public:
					Die(int size);
	int 			roll(void);

private:
	int 			sides;
};

#endif /* DIE_H_ */
