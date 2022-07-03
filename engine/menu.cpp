#include "menu.hpp"
#include "../utils/log.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

Menu::Menu(){
	this->font = al_load_ttf_font("./fonts/Pattaya/Pattaya-Regular.ttf", 24, 0);
	if (!this->font)
		LOG::game_abort("failed to load font: pirulen.ttf");
}

void Menu::draw(void){
	// background color
	al_clear_to_color(al_map_rgb(100, 100, 100));

	// draw rectangle
	al_draw_rectangle(left_space, upper_space,
					left_space + space_width, upper_space + space_height,
					al_map_rgb(255, 255, 255), 0);
	// draw info message
	char welcome_message[] ="Welcome to sprout HW2";
	char info_message[] ="Press any key to play";
	al_draw_text(this->font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 300,
				ALLEGRO_ALIGN_CENTER, welcome_message);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 350,
				ALLEGRO_ALIGN_CENTER, info_message);
	al_flip_display();
}

void Menu::destroy(void){
	al_destroy_font(this->font);
}

Menu::~Menu(void){
	this->destroy();
}

void Menu::update(void) {
	// check keyboard status
	for(auto i:key_state){
		if(i){
			this->done = true;
		}
	}
}
