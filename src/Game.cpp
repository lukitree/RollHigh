/*
 * Game.cpp
 *
 *  Created on: Apr 1, 2015
 *      Author: eddy
 */

#include "Game.h"
#include <algorithm>
#include "pair_compare.h"
#include <string>

Game::Game() : p1(), p2(), p3(), p4(), ui(){
	initscr();
	refresh();
	player_count = 0;
	play = true;
	all_players_done = false;
}

Game::~Game(void){
	endwin();
}

void
Game::init(void){
	get_player_count();
	get_player_names();
	get_player_input();
	spawn_player_window();
	init_ui();
}

void
Game::run(void){
	roll.start_cycle(10);
	while(play)
	{
		poll_input();
		while(!all_players_done && play){
			update_player_numbers();
			poll_input();
			check_all_players_done();
		}
		check_numbers();
		assign_points();
		update_scoreboard();
		prompt_play_again();
		reset_players();
		//pause();
	}
	roll.stop_cycle();
}

void
Game::pause(void){
	std::cerr << "Paused" << std::endl;
	move(0, 0);
	cbreak();
	noecho();
	timeout(-1);
	getch();
	std::cerr << "Continuing..." << std::endl;
}

void
Game::print_top(const std::string& msg){
	move(0, 0);
	printw(msg.c_str());
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
		player_count -= '0';
	}while(player_count > 4 || player_count < 2);
	std::string format_string;
	format_string = std::to_string(player_count) + " players selected.";
	print_top(format_string.c_str());
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void
Game::get_player_names(void){
	//Player players[4] {p1, p2, p3, p4};
	std::vector<Player*> players {&p1, &p2, &p3, &p4};

	std::string name;
	char c;
	const int MAX_CHARS = 3;


	for(int i = 0; i < player_count; ++i)
	{
		std::string prompt;
		prompt = "Enter player " + std::to_string(i+1) + "'s name: ";
		print_top(prompt);
		while((c = getch()) != '\n')
		{
			std::string msg;
			switch(c)
			{
				case 127:
					if(!name.empty())
					{
						name.pop_back();
					}
					msg = prompt + name;
					print_top(msg.c_str());
					break;
				default:
					if (name.length() < MAX_CHARS)
					{
						name += c;
					}
					msg = prompt + name;
					print_top(msg.c_str());
			}
		}
		players[i]->set_name(name.c_str());
		name.clear();
	}
}

void
Game::spawn_player_window(void){
	switch (player_count)
	{
		case 4:
			p4.spawn(3, 35);
			//no break
		case 3:
			p3.spawn(5, 25);
			//no break
		case 2:
			p2.spawn(7, 15);
			p1.spawn(9, 5);
			break;
		default:
			std::cerr << "Error setting player count" << std::endl;
	}
}

void
Game::init_ui(void){
	ui.set_player_names(p1.get_name(), p2.get_name(), p3.get_name(), p4.get_name());
	ui.init(player_count);
	ui.set_player_scores(p1.get_score(), p2.get_score(), p3.get_score(), p4.get_score());
	ui.print_msg("hello there");
}

void
Game::update_player_numbers(void){
	int tmp = roll.get_number();
	switch(player_count)
	{
		case 4:
			p4.set_number(tmp);
			//no break
		case 3:
			p3.set_number(tmp);
			//no break
		case 2:
			p2.set_number(tmp);
			p1.set_number(tmp);
	}
	move(0,0);
}

void
Game::get_player_input(void){
	switch(player_count)
	{
		case 4:
			p4.set_input_key('m');
			//no break
		case 3:
			p3.set_input_key('b');
			//no break
		case 2:
			p2.set_input_key('c');
			p1.set_input_key('z');
	}
}

void
Game::check_all_players_done(void){
	int check = 0;
	switch(player_count)
	{
		case 4:
			if(p4.is_stopped())
				++check;
				//no break
		case 3:
			if(p3.is_stopped())
				++check;
				//no break
		case 2:
			if(p2.is_stopped())
				++check;
				//no break
		case 1:
			if(p1.is_stopped())
				++check;
	}

	if(check == player_count)
	{
		all_players_done = true;	
	}
	else
	{
		all_players_done = false;
	}
}

void
Game::poll_input(void){
	char input = 0;
	timeout(20);
	input = getch();

	if(input == p4.get_input_key())
	{
		p4.stop_on_number();
	}
	else if(input == p3.get_input_key())
	{
		p3.stop_on_number();
	}
	else if(input == p2.get_input_key())
	{
		p2.stop_on_number();
	}
	else if(input == p1.get_input_key())
	{
		p1.stop_on_number();
	}
	else
	{
		switch(input){
			case KEY::EXIT:
				play = false;
				break;
		}
	}
}

void
Game::check_numbers(void){
	switch(player_count){
		case 4:
			scores.push_back(std::make_pair(4, p4.get_number()));
			//no break
		case 3:
			scores.push_back(std::make_pair(3, p3.get_number()));
			//no break
		case 2:
			scores.push_back(std::make_pair(2, p2.get_number()));
			scores.push_back(std::make_pair(1, p1.get_number()));
	}
		std::sort(scores.begin(), scores.end(), pair_compare_greater);
}

void
Game::assign_points(void){
	int top_score;
	Player* player[5];
	switch(player_count)
	{
		case 4:
			player[4] = &p4;
			//no break
		case 3:
			player[3] = &p3;
			//no break
		case 2:
			player[2] = &p2;
			player[1] = &p1;
			player[0] = nullptr;
	}
	top_score = scores[0].second;

	for(auto i : scores)
	{
		if(i.second == top_score)
		{
			player[i.first]->increase_score();
		}
	}
}

void
Game::reset_players(void){
	switch(player_count)
	{
		case 4:
			p4.reset();
			//no break
		case 3:
			p3.reset();
			//no break
		case 2:
			p2.reset();
			p1.reset();
	}

	all_players_done = false;
	scores.clear();
	print_top("");
}

void
Game::update_scoreboard(void){
	ui.set_player_scores(p1.get_score(), p2.get_score(), p3.get_score(), p4.get_score());
//	std::cerr << "Scores:" << std::endl;
//	switch(player_count)
//	{
//		case 4:
//			std::cerr << p4.get_name() << ":\t" << p4.get_score() << std::endl;
//		case 3:
//			std::cerr << p3.get_name() << ":\t" << p3.get_score() << std::endl;
//		case 2:
//			std::cerr << p2.get_name() << ":\t" << p2.get_score() << std::endl;
//			std::cerr << p1.get_name() << ":\t" << p1.get_score() << std::endl;
//	}
}

void
Game::prompt_play_again(void){
	print_top("Press any key to continue, q to quit.");
	timeout(-1);
	char input = 0;
	input = getchar();

	switch(input)
	{
		case 'q':
			play = false;
			break;
		default:
			play = true;
			break;
	}
}

