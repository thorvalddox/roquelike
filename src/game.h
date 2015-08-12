#pragma once
#include "entity.h"
#include "binaryheap.h"
#include "gameevent.h"
#include "gui.h"

#include <memory>

class Game
{
public:
	std::vector<std::shared_ptr<Entity>> entities;
	GUI gui;

	Game();
	~Game();
	class _eventclass_{
	private:
		lib::binaryheap<game_event> priority_queue;	
		unsigned long long current_time;
	public:
		void add(Action action, unsigned int delay);
		void addEnemyAI(Enemy * unit, unsigned int delay);
		Action next();
	} event;

	void add_player(TilePos t);
	void add_enemy(TilePos t);
	void remove_entity();

	friend void Execute_enemy_AI(Game * game, Unit * target);
	void step();
};