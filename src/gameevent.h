#pragma once
#include "game.h"
#include "entities.h"


class Action
{
private:
	Game * game;
	Unit * target;
	int (*action) (Game *, Unit *);
	unsigned long long timestamp;
public:
	Action(Game * game, Unit * target, int (*action) (Game *, Unit *)): game(game), unit(unit), action(action){}
	int execute() {return action(game, target);}
	bool operator<(Action& act)	{return (this->timestamp < act.timestamp);}
	bool operator>(Action& act)	{return (this->timestamp > act.timestamp);}
};