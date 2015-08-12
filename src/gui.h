#pragma once
#include "rogue.h"
#include <allegro5/allegro.h>
#include "level.h"

class GUI
{
private:
	ALLEGRO_TIMER * timer;
	ALLEGRO_EVENT_QUEUE * queue;
	ALLEGRO_DISPLAY * display;
	ALLEGRO_BITMAP * tiles;
	void draw_tile(Rectangle, Point);

	struct
	{
		Rectangle view;
	} viewport;
public:
	GUI();
	~GUI();
	void draw_level(Level& l);
	void swap_buffer();
	GUI_event next_event();
};