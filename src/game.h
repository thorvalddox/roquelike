#pragma once
#include "entity.h"
#include "binaryheap.h"
#include "gameevent.h"
#include "gui.h"

class Game
{
public:
	std::vector<Entity *> entities;
	lib::binaryheap<game_event> priority_queue;
	unsigned long long current_time;
	GUI gui;

	Game();
	~Game();

	void step();
	Action nextevent();

};