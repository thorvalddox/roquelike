#include <iostream>
#include <allegro.h>
#include "level.h"


int main(int agrc, char *argv[])
{
    al_init();
    al_install_keyboard();
    //ALLEGRO_DISPLAY * display = al_create_display(640,480);
    Maze maze(5);
    maze.print(&std::cout);
    return 0;
}
