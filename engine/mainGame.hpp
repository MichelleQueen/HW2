#ifndef _MAINGAME_HPP
#define _MAINGAME_HPP


#include <list>
#include "../object/object.hpp"
#include "scene.hpp"
#include "../object/player.hpp"

class MainGame : public Scene{
	private:
		//store object which in the scene
		std::list<Object*> object_list;
		// store P1 and P2 
		Player *P1, *P2;
	public:
		MainGame();
		virtual ~MainGame();
		// store commonly used object image
		ALLEGRO_FONT *font;
		ALLEGRO_BITMAP *asteroid_img;
		ALLEGRO_BITMAP *bullet_img;
		ALLEGRO_BITMAP *bullet2_img;
		ALLEGRO_BITMAP *bullet3_img;
		ALLEGRO_BITMAP *bullet4_img;
		int winner;
		void draw(void) override;
		void destroy(void) override;
		void update(void) override;
		void initial(void);
};

#endif