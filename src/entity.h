#pragma once
#include "rogue.h"
#include <array>
#include "elements.h"

class Game;
class Entity;
class Unit;
class Player;
class Enemy;

typedef int (*AI_type) (Game *, Enemy *, direction *) ;

class Entity
{
protected:
	enum {ENTITY_PLAYER, ENTITY_ENEMY, ENTITY_STAIRS, ENTITY_TREASURE} type;
public:
	TilePos p;
	Entity(TilePos p): p(p){}
	virtual ~Entity() {}
	virtual Rectangle sprite()=0;
};


class Unit: public Entity
{
public:

	std::array<bool,15> active_buffs;
	std::array<bool,8> active_stats;

	Unit(TilePos p):Entity(p) {}

	bool get_buff(Buff) const;
	bool get_stat(Stat) const;
	bool apply_buff(Game *, Buff_apply);
	~Unit() {}
};

class Player: public Unit
{
public:
	Player(TilePos p): Unit(p){type = ENTITY_PLAYER;}
	~Player(){}
	Rectangle sprite() {return Rectangle(0*16,4*16,16,16);}
};



class Enemy: public Unit
{
public:
	Enemy(TilePos p): Unit(p) {type = ENTITY_ENEMY;}
	struct {
		AI_type normal;
		AI_type snared;
		AI_type silenced;
	} AI;
	~Enemy(){}
	Rectangle sprite() {return Rectangle(1*16,0*16,16,16);}
};

class Treasure: public Entity
{
public:
	Treasure(TilePos p):Entity(p){type = ENTITY_TREASURE;}
	~Treasure();
	Rectangle sprite() {return Rectangle(2*16,9*16,16,16);}
};

class Stairs: public Entity
{
public:
	Stairs(TilePos p):Entity(p) {type = ENTITY_STAIRS;}
	~Stairs();
	Rectangle sprite() {return Rectangle(13*16,3*16,16,16);}
};
