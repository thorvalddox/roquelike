#pragma once
#include "rogue.h"

class Game;
class Entity;
class Unit;
class Player;
class Enemy;

typedef int (*AI_type) (Game *, Enemy *, direction *) ;

class Entity
{
	enum {ENTITY_PLAYER, ENTITY_ENEMY, ENTITY_STAIRS, ENTITY_TREASURE} type;
public:
	Point p;
	virtual ~Entity() {}
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
public:
	struct_status status_effects;
	~Unit() {}
};

class Player: public Unit
{
public:
	~Player(){}
};



class Enemy: public Unit
{
public:
	
	AI_type AI;
	~Enemy(){}
};