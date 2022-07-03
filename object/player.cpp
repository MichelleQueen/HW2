#include <string>
#include <iostream>
#include "player.hpp"

// initialize parameter
Player::Player(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h): Object(_x, _y, _speedX, _speedy, path, w, h){
	this->hp = 100;
	this->bullet_power = 3;
	this->exp = 0;
	this->energy = 100;
	this->bullet_cool = 0;
}

// update new position and reset speed to avoid repeat move
bool Player::update() {
	this->x += this->speedX;
	this->y += this->speedY;
	this->speedX = 0;
	this->speedY = 0;
	return true;
}


