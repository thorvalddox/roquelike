#pragma once
#include "rogue.h"
#include <allegro5/allegro.h>
class GUI
{
private:
	ALLEGRO_TIMER * timer;
	ALLEGRO_EVENT_QUEUE * queue;
	ALLEGRO_DISPLAY * display;

public:
	GUI();
	~GUI();
	GUI_event next_event();
};