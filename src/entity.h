#pragma once
#include "enum.h"

class Game;
class Entity;
class Unit;
class Player;
class Enemy;

typedef int (*) (Game *, Enemy *, direction *) AI_type;

enum entity_type
{
	ENTITY_PLAYER, ENTITY_ENEMY, ENTITY_STAIRS, ENTITY_TREASURE;
};



class Entity
{
	Entity_type::type type;
	int x, y;
};

struct struct_status
{
	unsigned blinded:1;
	unsigned stunned:1;
	unsigned slowed:1;
	unsigned on_fire:1;
};

class Unit: public Entity
{
	struct_status status_effects;
};

class Player: public Unit
{

};



class Enemy: public Unit
{
	AI_type AI;
};