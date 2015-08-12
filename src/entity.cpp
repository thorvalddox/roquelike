#include "entity.h"





bool Unit::get_buff(Buff b) const
{
	return active_buffs[(int)b];
}

bool Unit::get_stat(Stat s) const
{
	return active_stats[(int)s];
}

bool Unit::apply_buff(Game * game, Buff_apply buff_apply)
{
	Buff b = buff_apply.first;
	//int delay = buff_apply.second;
	active_buffs[(int)b] = true;
	return true;
}