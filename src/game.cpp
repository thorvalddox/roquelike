#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::addevent(game_event event)
{

}

Action Game::nextEvent()
{
	game_event res = priority_queue.extractmin();
	current_time = res.timestamp;
	return res.action;
}