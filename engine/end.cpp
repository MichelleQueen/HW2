#include <string>
#include "end.hpp"
#include "../utils/log.hpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

End::End(){
	this->font = al_load_ttf_font("./fonts/Pattaya/Pattaya-Regular.ttf", 24, 0);
	if (!this->font)
		LOG::game_abort("failed to load font: pirulen.ttf");
}

void End::draw(void){
	// background color
	al_clear_to_color(al_map_rgb(100, 100, 100));

	// draw rectangle
	al_draw_rectangle(left_space, upper_space,
					left_space + space_width, upper_space + space_height,
					al_map_rgb(255, 255, 255), 0);
	// draw info message
	std::string win_message = "Win the game";
	if(this->winner == 1){
		win_message = "Player 1 " + win_message;
	}else{
		win_message = "Player 2 " + win_message;
	}
	std::string info_message ="Press ENTER to play or ESC to exit";
	al_draw_text(this->font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 300,
				ALLEGRO_ALIGN_CENTER, win_message.c_str());
	al_draw_text(this->font, al_map_rgb(255, 255, 255), SCREEN_W / 2, 350,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	al_flip_display();
}

void End::destroy(void){
	al_destroy_font(this->font);
}

// release resource
End::~End(void){
	this->destroy();
}

void End::update(void) {
	// check keyboard status
	if(key_state[ALLEGRO_KEY_ESCAPE]){
		this->finish = true;
		this->done = true;
	}
	if(key_state[ALLEGRO_KEY_ENTER]){
		key_state[ALLEGRO_KEY_ENTER] = 0;
		this->done = true;
	}
}
