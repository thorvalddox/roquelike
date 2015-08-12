#include <iostream>
#include "level.h"
#include "game.h"
#include "gui.h"
int main(int agrc, char *argv[])
{
    al_init();
    al_install_keyboard();
    GUI gui;
    Level level(5, 10);
    level.print(&std::cout);
    while (gui.next_event().type != GUI_event::EXIT);
    return 0;
}
