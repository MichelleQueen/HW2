#ifndef _POTION_HPP
#define _POTION_HPP

#include "object.hpp"
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Potion : public Object{
	public:
		Potion(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h, int type);
		Potion(float _x, float _y, float _speedX, float _speedy, ALLEGRO_BITMAP *_img, int type);
		// type of the potion. (0 or 1 or 2 or 3 or 4)
        // 0 for HP+30.  1 for bullet_power+1.  2 for energy+100.
		// 3 for shield 20 sec.     4 for change HP with another player
		int type;
};

#endif
