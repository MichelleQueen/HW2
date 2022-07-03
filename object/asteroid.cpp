#include <string>
#include <iostream>
#include "asteroid.hpp"


Asteroid::Asteroid(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h): Object(_x, _y, _speedX, _speedy, path, w, h){

}


Asteroid::Asteroid(float _x, float _y, float _speedX, float _speedy, ALLEGRO_BITMAP *_img): Object(_x, _y, _speedX, _speedy, _img){

}


