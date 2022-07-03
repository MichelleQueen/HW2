#ifndef _ASTEROID_HPP
#define _ASTEROID_HPP

#include "object.hpp"
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Asteroid : public Object{
	public:
		Asteroid(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h);
		Asteroid(float _x, float _y, float _speedX, float _speedy, ALLEGRO_BITMAP *_img);
};

#endif