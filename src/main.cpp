#include <iostream>
#include "level.h"
#include "game.h"
#include "gui.h"

int main(int argc, char *argv[])
{
    al_init();
    al_install_keyboard();
    GUI gui;
    Level level(5, 10);
    level.print(&std::cout);
    GUI_event ev;
    while ((ev = gui.next_event()).type != GUI_event::EXIT)
    {
    	if (ev.type == GUI_event::KEYCHAR)
		{
			std::cout << (char) ev.value;
			std::cout.flush();
		}
		if (ev.type == GUI_event::TIMER)
		{
			gui.draw_level(level);
			gui.swap_buffer();
		}
    }
    return 0;
}
