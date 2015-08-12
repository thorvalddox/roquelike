#pragma once
#include "rogue.h"
#include <array>

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


class Unit: public Entity
{
public:

	std::array<Bool,15> active_buffs;
	std::array<Bool,8> active_stats;

	bool get_buff(Buff) const;
	bool get_stat(Stat) const;
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
