#ifndef _IMAGEPROCESS_HPP
#define _IMAGEPROCESS_HPP
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
namespace ImageProcess{
	// load bitmap from filename and set this size w*h 
	ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, int w, int h);
}
#endif
