#include "scene.hpp"
#include "../utils/log.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

Scene::~Scene(){
	
}
void Scene::start_event_loop(void) {
	
	ALLEGRO_EVENT event;
	while (!this->done) {
		al_wait_for_event(event_queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){

			// Event for clicking the window close button.
			this->done = true;
			this->finish = true;
		}else if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			LOG::game_log("Key with keycode %d down", event.keyboard.keycode);
			key_state[event.keyboard.keycode] = true;
		} else if (event.type == ALLEGRO_EVENT_KEY_UP) {
			LOG::game_log("Key with keycode %d up", event.keyboard.keycode);
			key_state[event.keyboard.keycode] = false;
		} else if (event.type == ALLEGRO_EVENT_TIMER) {
			// Event for redrawing the display.
			if (event.timer.source == update_timer) {
				this->update();
				this->draw();
			}
		}
	}
}