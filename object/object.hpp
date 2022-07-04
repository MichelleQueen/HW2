#ifndef _OBJECT_HPP
#define _OBJECT_HPP
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "../utils/log.hpp"
#include "../utils/imageProcess.hpp"
#include <string>
#include <iostream>

extern const int scale;
extern const int width;
extern const int height;
extern const int space_width;
extern const int space_height;
extern const int upper_space;
extern const int left_space;
extern const int word_space;

class Object{
	public:	
		// construct with image path name and size
		Object(float _x, float _y, float _speedX, float _speedY, std::string path, int w, int h){
			this->x = _x;
			this->y = _y;
			this->speedX = _speedX;
			this->speedY = _speedY;
			this->Path = path;

			this->img = ImageProcess::load_bitmap_at_size(path.c_str(), w, h);
			if (!this->img)
				LOG::game_abort("failed to load image: object");
		};
		// construct with bitmap point
		Object(float _x, float _y, float _speedX, float _speedY, ALLEGRO_BITMAP *_img){
			this->x = _x;
			this->y = _y;
			this->speedX = _speedX;
			this->speedY = _speedY;
			this->img = _img;
		};
		Object(){}
		virtual ~Object(){
			this->destroy();
		}
		// release resource
		void destroy(void){
			al_destroy_bitmap(this->img);
		}
		// object image
		ALLEGRO_BITMAP *img;
		// object position and speed
		float x;
		float y;
		float speedX;
		float speedY;
		string Path;



		// this will called when scene want to update the object position
		virtual bool update(void){
			this->x += this->speedX;
			this->y += this->speedY;
			//return false when the object out of range
			if(this->x < 0 || this->x >= width || this->y < 0 || this->y >= height){

				return false;
			} 

			return true;
		}
		
		
};

#endif
