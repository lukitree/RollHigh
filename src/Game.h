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

class Game {
public:
					Game(void);
					~Game(void);
	void			run(void);

private:
	void 			print_top(const char* msg);
	void 			get_player_count(void);
	void 			get_player_names(void);
	void 			pause(void);
	void 			setup_players(void);
	void 			setup_ui(void);

	int 			player_count;
	Player			p1;
	Player 			p2;
	Player 			p3;
	Player 			p4;
	UI				ui;
};

#endif /* GAME_H_ */
