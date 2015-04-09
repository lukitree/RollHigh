/*
 * Game.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#include "Game.h"

Game::Game() : p1(1), p2(2), p3(3), p4(4), ui(){
	initscr();
	refresh();
	player_count = 0;
	play = true;
}

Game::~Game(void){
	endwin();
}

void
Game::init(void){
	get_player_count();
	get_player_names();
	setup_players();
	setup_ui();
	pause();
}

void
Game::run(void){
	while(play)
	{
		roll.start_cycle(10);


		roll.stop_cycle();
	}
}

void
Game::pause(void){
	addch('\n');
	addch('>');
	move(0, 0);
	cbreak();
	noecho();
	getch();
}

void
Game::print_top(const char* msg){
	move(0, 0);
	printw(msg);
	clrtoeol();
	refresh();
}

void
Game::get_player_count(void){
	cbreak();
	noecho();
	do	
	{
		print_top("How many players? (2-4)?: ");
		player_count = getch();
		player_count = player_count - '0';
	}while(player_count > 4 || player_count < 2);
	std::string format_string;
	format_string = std::to_string(player_count) + " players selected.";
	print_top(format_string.c_str());
}

void
Game::get_player_names(void){
	switch(player_count){
		case 4:
			p4.set_name("Bob");
		case 3:
			p3.set_name("Ted");
		case 2:
			p2.set_name("Joe");
			p1.set_name("Will");

	}
}

void
Game::setup_players(void){
	switch (player_count)
	{
		case 4:
			p4.spawn(3, 35);
		case 3:
			p3.spawn(5, 25);
		case 2:
			p2.spawn(7, 15);
			p1.spawn(9, 5);
			break;
		default:
			std::cerr << "Error setting player count" << std::endl;
	}
}

void
Game::setup_ui(void){
	ui.spawn(Type::Msg);
	ui.spawn(Type::Score);
	ui.print_msg("hello there");
}
