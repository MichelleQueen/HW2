#include <string>
#include <iostream>
#include "potion.hpp"


Potion::Potion(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h, int _type): Object(_x, _y, _speedX, _speedy, path, w, h){
	this->type = _type;
}


Potion::Potion(float _x, float _y, float _speedX, float _speedy, ALLEGRO_BITMAP *_img, int _type): Object(_x, _y, _speedX, _speedy, _img){
	this->type = _type;
}


