#include <iostream>
#include "level.h"
#include "game.h"
#include "gui.h"

#include <memory>

int main(int argc, char *argv[])
{
    al_init();
    al_install_keyboard();
    Game game;
    game.add_player(TilePos(5,5));
    game.add_enemy(TilePos(10,10));
    GUI& gui = game.gui;
    Level level(5, 10);
    level.print(&std::cout);
    GUI_event ev;
    while ((ev = gui.next_event()).type != GUI_event::EXIT)
    {
    	if (ev.type == GUI_event::KEYPRESS)
		{

		}
		if (ev.type == GUI_event::TIMER)
		{
			gui.draw_level(level);
			for (std::shared_ptr<Entity> e:game.entities)
				gui.draw_entity(e.get());
			gui.swap_buffer();
		}
    }
    return 0;
}
