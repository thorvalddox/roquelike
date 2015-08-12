#pragma once
#include "entity.h"
#include "binaryheap.h"

class Game
{
public:
	std::vector<Entity *> entities;
	binaryheap<game_event> priority_queue;
};