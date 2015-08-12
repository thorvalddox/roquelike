#include "entity.h"





bool Unit::get_buff(Buff b) const
{
	return active_buffs[(int)b];
}

bool Unit::get_stat(Stat s) const
{
	return active_stats[(int)s];
}