#ifndef _MODEL_HPP
#define _MODEL_HPP
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

extern const int width;
extern const int height;


class Model{
	public:
		// called by game start
		virtual void initial() = 0;
		// called by every update time
		// GameMap is current game status
		// return integer array is as same as the key_state array
		virtual int *update(std::list<Object*> object_list) = 0;
};

#endif