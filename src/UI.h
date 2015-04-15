/*
 * UI.h
 *
 *  Created on: Apr 5, 2015
 *      Author: eddy
 */

#ifndef UI_H_
#define UI_H_

#include <ncurses.h>
#include <string>

class UI{
public:
	void 			init(int pcount);
	void 			print_msg(const char* msg);
	void 			set_player_scores(int p1, int p2, int p3, int p4);
	void 			set_player_names(const std::string& p1,
									const std::string& p2,
									const std::string& p3,
									const std::string& p4);

private:
	void			spawn_scoreboard(void);
	void			spawn_msgbox(void);
	void 			player_names_to_scoreboard(void);

	int 			active_players;
	WINDOW*			msg_box;	
	WINDOW*			score_box;
	std::string 	p1_name;
	std::string 	p2_name;
	std::string 	p3_name;
	std::string 	p4_name;
};

#endif /* UI_H_ */
