#ifndef _SCENE_HPP
#define _SCENE_HPP

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

extern ALLEGRO_DISPLAY *game_display;
extern ALLEGRO_FONT *font;
extern ALLEGRO_BITMAP *img;
extern ALLEGRO_TIMER *update_timer;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern bool key_state[ALLEGRO_KEY_MAX];

extern const int SCREEN_W;
extern const int SCREEN_H;
extern const int FPS;

extern const int scale;
extern const int width;
extern const int height;
extern const int space_width;
extern const int space_height;
extern const int upper_space;
extern const int left_space;
extern const int word_space;

extern int runtime;


class Scene{
	public:
		virtual ~Scene();
		bool done = false;
		bool finish = false;
		/* Declare function prototypes. */
		// Initialize variables and resources.
		// Allows the game to perform any initialization it needs before
		// starting to run.
		// Draw to display.
		// This is called when the game should draw itself.
		virtual void draw(void) = 0;
		// Release resources.
		// Free the pointers we allocated.
		virtual void destroy(void) = 0;
		// start event loop check draw and update every frame
		void start_event_loop(void);
		// update the scene
		virtual void update(void) = 0;
};

#endif