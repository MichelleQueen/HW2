#ifndef _END_HPP
#define _END_HPP



#include "scene.hpp"


class End : public Scene{
	public:
		End();
		~End();
		ALLEGRO_FONT *font;
		void draw(void) override;
		void destroy(void) override;
		void update(void) override;
		int winner;
};

#endif