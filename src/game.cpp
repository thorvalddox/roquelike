#include "game.h"

Game::Game()
{

}

Game::~Game()
{

}


void Game::addEvent(Action action, unsigned int delay)
{
	game_event event(action, current_time + delay);
	priority_queue.add(event);
}

Action Game::nextEvent()
{
	game_event res = priority_queue.extractmin();
	current_time = res.timestamp;
	return res.action;
}