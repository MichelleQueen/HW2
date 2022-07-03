#include "mainGame.hpp"
#include "../utils/log.hpp"
#include "../utils/imageProcess.hpp"
#include "../object/object.hpp"
#include "../object/player.hpp"
#include "../object/bullet.hpp"
#include "../object/asteroid.hpp"
#include "../object/potion.hpp"
#include <iostream>
#include <string>
#include <utility>
#include <random>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

// check collision
bool collision(Object *a, Object *b){
	if(dynamic_cast<Player*> (a)){
		if(b->x >= a->x && b->x <= a->x + 2 && b->y >= a->y && b->y <= a->y + 2)return true; // for the case that a is Player*
	}else if(dynamic_cast<Player*> (b)){
		if(a->x >= b->x && a->x <= b->x + 2 && a->y >= b->y && a->y <= b->y + 2)return true; // for the case that b is Player*
	}else{
		if(a->x+1 >= b->x && a->x < b->x + 1 && a->y+1 >= b->y && a->y < b->y + 1)return true; // for the case that neither a nor b are Player*
	}
	return false;
}

// transfer integer to string 
std::string intToChar(int number){
	std::string s = std::to_string(number);
	return s;
}

MainGame::MainGame() {
	srand(time(NULL));
	// load font resource
	this->font = al_load_ttf_font("./fonts/Pattaya/Pattaya-Regular.ttf", 24, 0);
	if (!this->font)
		LOG::game_abort("failed to load font: pirulen.ttf");
	// load object image
    this->asteroid_img = ImageProcess::load_bitmap_at_size("./image/asteroid.png", scale, scale * 2);

    if (!this->asteroid_img){
        LOG::game_abort("failed to load asteroid image");
	}
	// load bullet image
	this->bullet_img = ImageProcess::load_bitmap_at_size("./image/bullet.png", scale, scale * 2);
	if (!this->bullet_img)
		LOG::game_abort("failed to load bullet image");
	// load another bullet image
	this->bullet2_img = ImageProcess::load_bitmap_at_size("./image/bullet2.png", scale, scale * 2);
	if (!this->bullet2_img)
		LOG::game_abort("failed to load bullet2 image");
	
}

void MainGame::initial(void){
	// clear object list
	this->object_list.clear();
	// reset Player1 and Player2
	this->P1 = new Player(40, 18, 0, 0, "./image/ship1.png", scale * 3, scale * 6);
	this->P2 = new Player(40, 5, 0, 0, "./image/ship2.png", scale * 3, scale * 6);
	this->p3 = new Player(20, 18, 0, 0, "./image/jet1.png", scale * 3, scale * 6);
	this->p4 = new Player(20, 5, 0, 0, "./image/jet2.png", scale * 3, scale * 6);
	this->object_list.push_back(this->P1);
	this->object_list.push_back(this->P2);
	this->object_list.push_back(this->P3);
	this->object_list.push_back(this->P4);
}

void MainGame::draw(void) {
	// background color
	al_clear_to_color(al_map_rgb(100, 100, 100));

	// draw rectangle
	al_draw_rectangle(left_space, upper_space,
					left_space + space_width, upper_space + space_height,
					al_map_rgb(255, 255, 255), 0);
	// draw mid line
	al_draw_line(left_space, upper_space + (space_height / 2), left_space + space_width, upper_space + (space_height / 2),
   al_map_rgb(255, 255, 255), 0);

	// Render title text.
	std::string info_message;
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space, 30,
				ALLEGRO_ALIGN_CENTER, "Player 2");
	info_message = "HP:" + intToChar(this->P2->hp);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space, 30,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	info_message = "Bullet_power:" + intToChar(this->P2->bullet_power);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space * 2, 30,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	info_message = "Exp:" + intToChar(this->P2->exp);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space * 3, 30,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	info_message = "Energy:" + intToChar(this->P2->energy);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space * 4, 30,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
		
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space, 750,
				ALLEGRO_ALIGN_CENTER, "Player 1");
	info_message = "HP:" + intToChar(this->P1->hp);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space, 750,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	info_message = "Bullet_power:" + intToChar(this->P1->bullet_power);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space * 2, 750,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	info_message = "Exp:" + intToChar(this->P1->exp);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space * 3, 750,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());
	info_message = "Energy:" + intToChar(this->P1->energy);
	al_draw_text(this->font, al_map_rgb(255, 255, 255), left_space + word_space * 4, 750,
				ALLEGRO_ALIGN_CENTER, info_message.c_str());

	// Draw comic.
	for(auto obj : this->object_list){
		if(dynamic_cast<Player*> (obj)){
			// Player's size is 3 * scale * 3 * (scale * 2) 
			al_draw_bitmap(obj->img, left_space + obj->x * scale, upper_space + obj->y * scale * 2, 0);
		}else{
			// every object's size is scale * (scale * 2)
			al_draw_bitmap(obj->img, left_space + obj->x * scale, upper_space + obj->y * scale * 2, 0);
		}
	}
	// render scene
	al_flip_display();
}

// release resource
void MainGame::destroy(void) {
	// al_destroy_bitmap(this->img);
	al_destroy_font(this->font);
	al_destroy_bitmap(this->asteroid_img);
	al_destroy_bitmap(this->bullet_img);
	al_destroy_bitmap(this->bullet2_img);
}

MainGame::~MainGame(){
	// release object resource
	for(auto obj : this->object_list){
		//obj->destroy();         與下面那行重複意思
		delete obj;
	}
	this->destroy();
}

void MainGame::update(void) {
	// set Player speed
	float speed = 1;
	// update game run time
	runtime++;
	// update player parameter
	this->P1->energy = std::min(100, this->P1->energy + 1);
	this->P2->energy = std::min(100, this->P2->energy + 1);
	this->P1->bullet_power += this->P1->exp / 100;
	this->P1->exp %= 100;
	this->P2->bullet_power += this->P2->exp / 100;
	this->P2->exp %= 100;
	this->P1->bullet_cool = std::max(0, this->P1->bullet_cool - 1);
	this->P2->bullet_cool = std::max(0, this->P2->bullet_cool - 1);

	// if a player dies then the game ends.
	if(this->P1->hp <= 0 || this->P2->hp <= 0){
		if(this->P1->hp <= 0){
			this->winner = 2;
		}else{
			this->winner = 1;
		}
		this->done = true;
	}

    // if asdw is pressed then player1 moves.
    // player1 will move from (P1->x, P1->y) to (P1->x + P1->speedX, P1->y + P1->speedY)
	if(key_state[ALLEGRO_KEY_D]){
		this->P1->speedX += speed;
	}
	if(key_state[ALLEGRO_KEY_A]){
		this->P1->speedX -= speed;
	}
	if(key_state[ALLEGRO_KEY_W]){
		this->P1->speedY -= speed;
	}
	if(key_state[ALLEGRO_KEY_S]){
		this->P1->speedY += speed;
	}
	
    // We cannot let (P1->x + P1->speedX, P1->y + P1->speedY) be out of bound.
	if(this->P1->x + this->P1->speedX > width - 3 || this->P1->x + this->P1->speedX < 0 ){
		this->P1->speedX = 0;
	}
	if(this->P1->y + this->P1->speedY > height - 3 || this->P1->y + this->P1->speedY < height / 2 ){
		this->P1->speedY = 0;
	}
    
	// when player1 shoot (press space), create new bullet object in front of player1
	if(key_state[ALLEGRO_KEY_SPACE] && this->P1->energy >= 20 && this->P1->bullet_cool == 0){
		this->P1->bullet_cool = 5;
		this->P1->energy -= 20;
		ALLEGRO_BITMAP *tmp = al_clone_bitmap(this->bullet_img);
		Object *bullet = new Bullet(this->P1->x + 1, this->P1->y - 1, 0, -1, tmp, 1);
		this->object_list.push_back(bullet);
	}

	int *action =a->update();
	//action=[0,1,0,1,1...]

    // if up down left right is pressed then player2 moves.
	if(action[ALLEGRO_KEY_RIGHT]){
		this->P2->speedX += speed;
	}
	if(action[ALLEGRO_KEY_LEFT]){
		this->P2->speedX -= speed;
	}
	if(action[ALLEGRO_KEY_UP]){
		this->P2->speedY -= speed;
	}
	if(action[ALLEGRO_KEY_DOWN]){
		this->P2->speedY += speed;
	}
    
    // We cannot let (P2->x + P2->speedX, P2->y + P2->speedY) be out of bound.
	if(this->P2->x + this->P2->speedX > width - 3 || this->P2->x + this->P2->speedX < 0 ){
		this->P2->speedX = 0;
	}
	if(this->P2->y + this->P2->speedY > height / 2 - 3 || this->P2->y + this->P2->speedY < 0 ){
		this->P2->speedY = 0;
	}
	
    // when player2 shoot (press enter), create new bullet object in front of player2
	if(action[ALLEGRO_KEY_ENTER] && this->P2->energy >= 20 && this->P2->bullet_cool == 0){
		this->P2->bullet_cool = 5;
		this->P2->energy -= 20;
		ALLEGRO_BITMAP *tmp = al_clone_bitmap(this->bullet_img);
		Object *bullet = new Bullet(this->P2->x + 1, this->P2->y + 3, 0, 1, tmp, 2);
		this->object_list.push_back(bullet);
	}

	// create asteroid
	int probability_inverse = 120000 / std::min(120000, runtime);
	if(rand() % probability_inverse == 0){
		int side = rand() % 4;
		Object *asteroid;
		ALLEGRO_BITMAP *tmp = al_clone_bitmap(this->asteroid_img);
		if(side == 0){
			asteroid = new Asteroid(rand() % width, 0, 0, 0.1, tmp);
		}else if(side == 1){
			asteroid = new Asteroid(rand() % width, height, 0, -0.1, tmp);
		}else if(side == 2){
			asteroid = new Asteroid(0, rand() % height, 0.2, 0, tmp);
		}else if(side == 3){
			asteroid = new Asteroid(width, rand() % height, -0.2, 0, tmp);
		}
		this->object_list.push_back(asteroid);
	}

	// create potion
	if(rand() % 600 == 0){
		int type = rand() % 4;
		std::string path = "./image/potion" + intToChar(type) + ".png";
		Object *potion = new Potion(rand() % width, rand() % height, 0, 0, path.c_str(), scale, scale * 2, type);
		this->object_list.push_back(potion);
	}

	// update all object in the scene
	for(auto obj = this->object_list.begin() ; obj != this->object_list.end() ;){
		if(!(*obj)->update()){
			delete *obj;
			obj = this->object_list.erase(obj);
		}else{
			 obj++;
		}
	}

	// check collision and update game
	for(auto from = this->object_list.begin() ; from != this->object_list.end() ;){
		// check erase "from" object
		bool flag = 0;
		for(auto to = this->object_list.begin() ; to != this->object_list.end() ;){
			// not collision or collision to itself
			if(from == to || !collision(*from, *to)){
				to++;
			}else if(dynamic_cast<Player*> (*from) && dynamic_cast<Bullet*> (*to)){
				// player collide to bullet
				auto py = dynamic_cast<Player*> (*from);
				auto bu = dynamic_cast<Bullet*> (*to);
				// decrease player hp by bullet power
				if(bu->type == 1){
					py->hp -= this->P1->bullet_power;
				}else if(bu->type == 2){
					py->hp -= this->P2->bullet_power;
				}
				// erase bullet
				delete *to;
				to = this->object_list.erase(to);
			}else if(dynamic_cast<Player*> (*from) && dynamic_cast<Asteroid*> (*to)){
				// player collide asteroid
				auto py = dynamic_cast<Player*> (*from);
				// decrease player hp
				py->hp -= 3;
				// erase asteroid
				delete *to;
				to = this->object_list.erase(to);
			}else if(dynamic_cast<Bullet*> (*from) && dynamic_cast<Asteroid*> (*to)){
				// bullet collide to asteroid
				auto bu = dynamic_cast<Bullet*> (*from);
				// add player experience
				if(bu->type == 1){
					this->P1->exp += 20;
				}else if(bu->type == 2){
					this->P2->exp += 20;
				}
				// erase from(bullet)
				flag = 1;
				// erase asteroid
				delete *to;
				to = this->object_list.erase(to);
				break;
			}else if(dynamic_cast<Player*> (*from) && dynamic_cast<Potion*> (*to)){
				// player collide to potion
				auto py = dynamic_cast<Player*> (*from);
				auto po = dynamic_cast<Potion*> (*to);
				// check what type of the potion 
				if(po->type == 0){
                    py->hp = std::min(100, py->hp + 30);
				}else if(po->type == 1){
					py->bullet_power += 1;
				}else if(po->type == 2){
					py->energy += 100;
				}
				// erase potion
				delete *to;
				to = this->object_list.erase(to);
			}else if(dynamic_cast<Bullet*> (*from) && dynamic_cast<Bullet*> (*to)){
				// bullet collide bullet
                // erase both bullets
				flag = 1;
				delete *to;
				to = this->object_list.erase(to);
				break;
			}else if(dynamic_cast<Asteroid*> (*from) && dynamic_cast<Asteroid*> (*to)){
				// asteroid collide asteroid
                // erase both asteroids
				flag = 1;
				delete *to;
				to = this->object_list.erase(to);
				break;
			}else{
				// other object collide will skip
				to++;
			}
		}
		if(flag){
			delete *from;
			from = this->object_list.erase(from);
		}else{
			from++;
		}
	}
}
