/*
 * Roller.h
 *
 *  Created on: Apr 6, 2015
 *      Author: eddy
 */

#ifndef ROLLER_H_
#define ROLLER_H_
#include <thread>
#include <mutex>

class Roller{
public:
	void 			start_cycle(int size);
	void 			stop_cycle(void);
	int 			get_number(void);

private:
	void 			cycle(void);

	int				sides;
	int 			number;
	bool 			keep_cycling;
};

#endif /* ROLLER_H_ */
