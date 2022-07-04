#include "model.hpp"
#include "../object/player.hpp"
#include "mainGame.cpp"
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
void AI::initial(){
    int x=0
    int speedX=0;
    int y=0;
    int speedY=0;
}

void AI::update(list<Object*> object_list){
    int action[227];
    for(int i=0; i<227;i++){
       action[i]=0;
    }  
    //最優先 和 player1 比較左右(當player1 的跟屁蟲)
    Player *P1, *P2;
    for (auto it = object_list.begin(); it != object_list.end(); it++) {
        if (dynamic_cast<Player*> (*it)  != 0 ){ //find player
            this->img = ImageProcess::load_bitmap_at_size(path.c_str(), w, h);
            if (this->img = "./image/ship1.png";){ //check if is P1 (idk how to write
                P1 = dynamic_cast<Player*>(*it);  
            }
            else{
                P2 = dynamic_cast<Player*>(*it);
            }
        }
    }
    
    if(P1->x   <   P2->x){
        action[ALLEGRO_KEY_LEFT]=1;
    }
    
    if(P1->x   >   P2->x){
        action[ALLEGRO_KEY_RIGHT]=1;
    }

    if(P1->x   =   P2->x){
            // when shoot, create new bullet object in front of AI
        if(key_state[ALLEGRO_KEY_SPACE] && this->P1->energy >= 20 && this->P1->bullet_cool == 0){
            this->P1->bullet_cool = 5;
            this->P1->energy -= 20;
            ALLEGRO_BITMAP *tmp = al_clone_bitmap(this->bullet_img);
            Object *bullet = new Bullet(this->P1->x + 1, this->P1->y - 1, 0, -1, tmp, 1);
            this->object_list.push_back(bullet);
	}

    }

    //其次 和potion的位置比較上下左右(以獲得藥水)
    if(potion->x < P2->x){
        action[ALLEGRO_KEY_LEFT]=1;
    }

    if(potion->x > P2->x){
        action[ALLEGRO_KEY_RIGHT]=1;
    }

    if(potion->y  >  P2->y){
        action[ALLEGRO_KEY_UP]=1;
    }

    if(potion->y < P2->y){
        action[ALLEGRO_KEY_DOWN]=1;
    }


}
	