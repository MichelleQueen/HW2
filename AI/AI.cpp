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
    for (auto it = object_list.begin(); it != object_list.end(); ++it) {
        if (dynamic_cast<Player*>(it)  != 0 ){ //find player
            this->img = ImageProcess::load_bitmap_at_size(path.c_str(), w, h);
            if (this->img = "./image/ship1.png";){ //idk how ro write
                 P1 = dynamic_cast<Player*>(it);  
            }
            else{
                P2 = dynamic_cast<Player*>(it);
            }

        }
       
        if(P1 != nullptr){
        //換 P2 被 cast
            P2 = dynamic_cast<Player*>(it);  
        }
    }
    
    if(P1->x   <   P2->x){
        action[ALLEGRO_KEY_LEFT]=1;
    }
    if(P1->x   >   P2->x){
        action[ALLEGRO_KEY_RIGHT]=1;
    }

    if(P1->x   =   P2->x){
        //發射bullet
    }

    //其次 和potion的位置比較上下左右(以獲得藥水)
    if(potion->x < p2->x){
        action[ALLEGRO_KEY_LEFT]=1;
    }

    if(potion->x > p2->x){
        action[ALLEGRO_KEY_RIGHT]=1;
    }

    if(potion->y  >  p2->y){
        action[ALLEGRO_KEY_UP]=1;
    }

    if(potion->y < p2->y){
        action[ALLEGRO_KEY_DOWN]=1;
    }


}
	