/*
 * Game.h
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#ifndef GAME_H_
#define GAME_H_

#include <ncurses.h>
#include <iostream>
#include <string>
#include "Player.h"
#include "UI.h"
#include "Roller.h"
#include <vector>

enum KEY {EXIT = 'q', RESTART = 'r'};

class Game {
public:
					Game(void);
					~Game(void);
	void			run(void);
	void 			init(void);

private:
	void 			print_top(const std::string& msg);
	void 			get_player_count(void);
	void 			get_player_names(void);
	void 			get_player_input(void);
	void 			pause(void);
	void 			spawn_player_window(void);
	void 			init_ui(void);
	void 			update_player_numbers(void);
	void 			check_all_players_done(void);
	void 			poll_input(void);
	void 			check_numbers(void);
	void 			assign_points(void);
	void 			reset_players(void);
	void 			update_scoreboard(void);
	void 			prompt_play_again(void);

	std::vector<std::pair<int, int>>	scores;
	bool 			play;
	bool 			all_players_done;
	int 			player_count;
	Player			p1;
	Player 			p2;
	Player 			p3;
	Player 			p4;
	UI				ui;
	Roller 			roll;
};

#endif /* GAME_H_ */
