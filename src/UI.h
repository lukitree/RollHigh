/*
 * UI.h
 *
 *  Created on: Apr 5, 2015
 *      Author: eddy
 */

#ifndef UI_H_
#define UI_H_

#include <ncurses.h>
enum class Type{Msg, Score};

class UI{
public:
	void			spawn(Type type);
	void 			print_msg(const char* msg);

private:
	WINDOW*			msg_box;	
	WINDOW*			score_box;
};

#endif /* UI_H_ */
