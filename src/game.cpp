#include "game.h"

#define encapsulating_ptr(class, nestedinstance, this) (class *) ((void*)this - offsetof(class, nestedclass));

Game::Game()
{

}

Game::~Game()
{

}


void Game::_eventclass_::add(Action action, unsigned int delay)
{
	game_event event(action, current_time + delay);
	priority_queue.add(event);
}

void Game::_eventclass_::addEnemyAI(Enemy * unit, unsigned int delay)
{
	//return add(Action(encapsulating_ptr(Game, event, this), unit, unit->AI), delay);
}

Action Game::_eventclass_::next()
{
	game_event res = priority_queue.extractmin();
	current_time = res.timestamp;
	return res.action;
}

void Game::add_player(TilePos t)
{
	std::shared_ptr<Entity> player (new Player(t));
	entities.push_back(player);
}

void Game::add_enemy(TilePos t)
{
	std::shared_ptr<Entity> enemy (new Enemy(t));
	entities.push_back(enemy);
}

void Game::remove_entity()
{

}

int Execute_enemy_AI(Game * game, Unit * target)
{
	direction res [4];
	switch (target->AI.normal(game, target, res))
	{
		case 1:
		for (direction dir: res)
		{
			if (target.canmove(game, dir))
			{
				target.move(game, dir);
				break;
			}
		}

		case 0:
	}

}