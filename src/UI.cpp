/*
 * UI.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: eddy
 */

#include "UI.h"

void
UI::spawn(Type type){
	switch(type){
		case Type::Msg:
			msg_box = newwin(5, 70, 15, 0);
			box(msg_box,0, 0);
			wprintw(msg_box, "Game Messages");
			wrefresh(msg_box);
			break;
		case Type::Score:
			score_box = newwin(12, 20, 2, 50);
			box(score_box, 0, 0);
			wprintw(score_box, "Scoreboard");
			wrefresh(score_box);
			break;
	}
}

void
UI::print_msg(const char* msg){
	wmove(msg_box, 2, 3);
	wprintw(msg_box, msg);
	wrefresh(msg_box);
}
