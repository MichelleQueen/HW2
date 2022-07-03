#ifndef _BULLET_HPP
#define _BULLET_HPP

#include "object.hpp"
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Bullet : public Object{
	public:
		Bullet(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h, int type);
		Bullet(float _x, float _y, float _speedX, float _speedy, ALLEGRO_BITMAP *_img, int type);
		// record which player create this bullet
		int type; // 1 if shot by Player1. 2 if shot by Player2.
};

#endif
