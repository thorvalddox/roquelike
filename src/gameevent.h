#pragma once
#include "game.h"
#include "entity.h"

class Action
{
private:
	Game * game;
	Unit * target;
	int (*action) (Game *, Unit *);
public:
	Action(Game * game, Unit * target, int (*action) (Game *, Unit *)): game(game), target(target), action(action){}
	int execute() {return action(game, target);}
};

class game_event 
{
private:
	Action action;
	unsigned long long timestamp;
public:
	bool operator<(game_event& act)	{return (this->timestamp < act.timestamp);}
	bool operator>(game_event& act)	{return (this->timestamp > act.timestamp);}
};