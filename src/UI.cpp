/*
 * UI.cpp
 *
 *  Created on: Apr 5, 2015
 *      Author: eddy
 */

#include "UI.h"
#include <string>

void
UI::init(int p_count){
	active_players = p_count;

	spawn_msgbox();
	spawn_scoreboard();
}

void
UI::spawn_msgbox(void){
	msg_box = newwin(5, 70, 15, 0);
	box(msg_box,0, 0);
	wprintw(msg_box, "Game Messages");
	wrefresh(msg_box);
}

void
UI::print_msg(const char* msg){
	wmove(msg_box, 2, 3);
	wprintw(msg_box, msg);
	wrefresh(msg_box);
}

void
UI::spawn_scoreboard(void){
	score_box = newwin(12, 20, 2, 50);
	box(score_box, 0, 0);
	wprintw(score_box, "Scoreboard");
	player_names_to_scoreboard();
	wrefresh(score_box);
}

void
UI::player_names_to_scoreboard(void){
	switch(active_players){
		case 4:
			wmove(score_box, 8, 3);
			wprintw(score_box, p4_name.c_str());
		case 3:
			wmove(score_box, 6, 3);
			wprintw(score_box, p3_name.c_str());
		case 2:
			wmove(score_box, 4, 3);
			wprintw(score_box, p2_name.c_str());
			wmove(score_box, 2, 3);
			wprintw(score_box, p1_name.c_str());
	}
}

void
UI::set_player_names(const std::string& p1, const std::string& p2, const std::string& p3, const std::string& p4){
	p1_name = p1;
	p2_name = p2;
	p3_name = p3;
	p4_name = p4;
}

void
UI::set_player_scores(int first, int second, int third, int fourth){
	std::string p1 = std::to_string(first);
	std::string p2 = std::to_string(second);
	std::string p3 = std::to_string(third);
	std::string p4 = std::to_string(fourth);

	int score_x_loc = 16;

	switch(active_players){
		case 4:
			wmove(score_box, 8, score_x_loc);
			wprintw(score_box, p4.c_str());
		case 3:
			wmove(score_box, 6, score_x_loc);
			wprintw(score_box, p3.c_str());
		case 2:
			wmove(score_box, 4, score_x_loc);
			wprintw(score_box, p2.c_str());
			wmove(score_box, 2, score_x_loc);
			wprintw(score_box, p1.c_str());
	}
	wrefresh(score_box);
}
