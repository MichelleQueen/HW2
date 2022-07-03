#ifndef _PLAYER_HPP
#define _PLAYER_HPP

#include "object.hpp"
#include <string>


class Player : public Object{
	public:
		Player(float _x, float _y, float _speedX, float _speedy, std::string path, int w, int h);
		virtual bool update() override;
    
        int hp; // between 0 and 100. if hp becomes 0 then the player loses.
        int bullet_power; // if your bullet hit your opponent, then your opponent's hp will decrease by bullet_power.
        int exp; // between 0 and 100. if your bullet hit an asteroid then exp += 20. if exp == 100 then bullet_power += 1.
        int energy; // between 0 and 100. shooting a bullet will decrease by 20.
		int bullet_cool; // between 0 and 5. you can shoot only if bullet_cool == 0.
        // You can check hackmd and other codes for more information.
};

#endif
