#include "gui.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>

#define TICK_PER_S 40

GUI::GUI()
{
    al_init();
    al_init_image_addon();
    al_init_primitives_addon();
    al_init_font_addon();
    al_install_keyboard();

    al_set_new_display_flags(ALLEGRO_WINDOWED);
    display = al_create_display(640, 480);
    al_set_window_position(display,10,10);
    al_set_window_title(display, "Rogue");

    timer = al_create_timer(1.0 / TICK_PER_S);
    queue = al_create_event_queue();

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
}

GUI::~GUI()
{
	al_stop_timer(timer);
	al_unregister_event_source(queue, al_get_keyboard_event_source());
	al_unregister_event_source(queue, al_get_display_event_source(display));
	al_unregister_event_source(queue, al_get_timer_event_source(timer));
	al_destroy_event_queue(queue);


	al_destroy_display(display);

	al_uninstall_keyboard();
	al_shutdown_font_addon();
	al_shutdown_primitives_addon();
	al_shutdown_image_addon();

    al_uninstall_system();
}

GUI_event GUI::next_event()
{
	static unsigned long long thetime = 0;
	while (1)
	{
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		GUI_event res;
		switch (event.type)
		{
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			res.type = GUI_event::EXIT;
			res.value = 0;
			return res;
		case ALLEGRO_EVENT_KEY_DOWN:
			res.type = GUI_event::KEYPRESS;
			res.value = event.keyboard.keycode;
			return res;
		case ALLEGRO_EVENT_KEY_CHAR:
			res.type = GUI_event::KEYCHAR;
			res.value = event.keyboard.unichar;
			return res;
		case ALLEGRO_EVENT_TIMER:
			res.type = GUI_event::TIMER;
			res.value = thetime++;
			return res;
		default:
			break;
		}
	}
}