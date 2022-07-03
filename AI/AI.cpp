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

void AI::update(){
    int action[227];
    for(int i=0; i<227;i++){
       action[i]=0;
    }  
    //最優先 和 player1 比較左右(當player1 的跟屁蟲)
    if(p1->x   <   p2->x){
        action[ALLEGRO_KEY_LEFT]=1;
    }
    if(p1->x   >   p2->x){
        action[ALLEGRO_KEY_RIGHT]=1;
    }

    if(p1->x   =   p2->x){
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
	