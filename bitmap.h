

#ifndef IMG_BITMAP
#define	IMG_BITMAP

#include "stm32_ub_vga_screen.h"
#include "images.h"


void load_bitmap(int img,int x_loc,int y_loc);
void draw_bitmap(bitmap_info * image,int x_loc,int y_loc);

typedef enum
{
	SMILEY,
	ANGRY,
	ARROW_UP,
	ARROW_DOWN,
	ARROW_LEFT,
	ARROW_RIGHT,
	HAMSTER
}images;

#endif
