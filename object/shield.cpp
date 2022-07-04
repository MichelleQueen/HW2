#include <string>
#include <iostream>
#include "shield.hpp"


Shield::Shield(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h, int _type): Object(_x, _y, _speedX, _speedy, path, w, h){
}


Shield::Shield(float _x, float _y, float _speedX, float _speedy, ALLEGRO_BITMAP *_img, int _type): Object(_x, _y, _speedX, _speedy, _img){
}

Shield::Shield(int t){
    int t=10;
    double timer=clock();
    while (t>0){
        if (clock()>timer+1000){
            timer=clock();//after each 10 sec, update timer 
            LOG::game_log(t);
            t--;
        }
    }
}
