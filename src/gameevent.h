#pragma once
#include "entity.h"
#include <memory>

class Game;
class Unit;

class Action
{
private:
public:
	Game * game;
	std::shared_ptr<Unit> target;
	int (* action) (Game *, Unit *);
	
	//LAMBDA: 
	//[buff] (Game* game, Unit * unit) -> int 
	//	{
	//		return buff;
	//	}

	Action(Game * game, Unit * target, int (*action) (Game *, Unit *)): game(game), target(target), action(action){}
	int execute() {return action(game, target.get());}
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