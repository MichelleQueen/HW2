#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "utils/log.hpp"
#include "engine/mainGame.hpp"
#include "engine/menu.hpp"
#include "engine/end.hpp"
///
ALLEGRO_DISPLAY *game_display;
ALLEGRO_FONT *font;
ALLEGRO_BITMAP *img;
ALLEGRO_TIMER *update_timer;
ALLEGRO_EVENT_QUEUE *event_queue;
bool key_state[ALLEGRO_KEY_MAX];

const int SCREEN_W = 1400;
const int SCREEN_H = 800;
const int FPS = 60;

const int scale = 12;
const int width = 80;
const int height = 26;
const int space_width = width * scale;
const int space_height = height * scale * 2;
const int upper_space = (SCREEN_H - space_height) / 2;
const int left_space = (SCREEN_W - space_width) / 2;
const int word_space = space_width / 4;

int runtime = 0;

// Program entry point.
// Returns program exit code.
int main(int argc, char **argv) {
    // Initialize allegro5 library
    if (!al_init())
        LOG::game_abort("failed to initialize allegro");

    game_display = al_create_display(SCREEN_W, SCREEN_H);
    if (!game_display) LOG::game_abort("failed to create display");
	if (!al_init_primitives_addon()) LOG::game_abort("failed to initialize primitives add-on");
    if (!al_init_font_addon()) LOG::game_abort("failed to initialize font add-on");
    if (!al_init_ttf_addon()) LOG::game_abort("failed to initialize ttf add-on");
    if (!al_init_image_addon()) LOG::game_abort("failed to initialize image add-on");
	if (!al_install_keyboard()) LOG::game_abort("failed to install keyboard");

    // create timer and event queue
    update_timer = al_create_timer(1.0f / FPS);
    if (!update_timer) LOG::game_abort("failed to create timer");

	event_queue = al_create_event_queue();
    if (!event_queue) LOG::game_abort("failed to create event queue");

	al_register_event_source(event_queue, al_get_display_event_source(game_display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(update_timer));
    al_start_timer(update_timer);

    LOG::game_log("Allegro5 initialized");
    // create scene
    Menu* menu = new Menu; // Welcome to sprout HW2. Press any key to play.
    MainGame* mainGame = new MainGame; // (playing...)
    End* end = new End; // ... wins the game. Press ENTER to play or ESC to exist.
    while(true){
        // enable scene and start event
        menu->done = false;
        LOG::game_log("Game begin");
        menu->start_event_loop();
        if(menu->finish)break; // if close window or ctrl+c, finish will be set true
        runtime = 0;
        mainGame->done = false;
        mainGame->initial();
        mainGame->start_event_loop();
        if(mainGame->finish)break; // if close window or ctrl+c, finish will be set true
        end->winner = mainGame->winner;
        end->done = false;
        end->start_event_loop();
        if(end->finish)break;
        LOG::game_log("Game end"); // if close window or ctrl+c or ESC, finish will be set true
        // if all finish are false, then back to the start of the while loop. (restart the game again)
    }
    // release resource
    delete menu;
    delete mainGame;
    delete end;
    al_destroy_timer(update_timer);
    al_destroy_event_queue(event_queue);
    al_destroy_display(game_display);
    LOG::game_log("Successful finish");
    return 0;
}

