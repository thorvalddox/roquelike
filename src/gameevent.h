#pragma once
#include "entity.h"

class Game;
class Unit;

class Action
{
private:
public:
	Game * game;
	Unit * target;
	int (* action) (Game *, Unit *);
	
	// [] (Game* game, Unit * unit) -> int {return 0;}

	Action(Game * game, Unit * target, int (*action) (Game *, Unit *)): game(game), target(target), action(action){}
	int execute() {return action(game, target);}
};

class game_event 
{
private:
public:
	Action action;
	unsigned long long timestamp;

	game_event(Action action, unsigned long long timestamp):action(action), timestamp(timestamp) {}
	bool operator<(game_event& act)	{return (this->timestamp < act.timestamp);}
	bool operator>(game_event& act)	{return (this->timestamp > act.timestamp);}
};