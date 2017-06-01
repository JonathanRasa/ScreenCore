#include "bitmap.h"



void load_bitmap(int img,int x_loc,int y_loc)
{
	switch(img)
	{
		case SMILEY:
			draw_bitmap(&smiley,x_loc,y_loc);
			break;
		case ANGRY:
			draw_bitmap(&angry,x_loc,y_loc);
			break;
		case ARROW_UP:
			draw_bitmap(&arrow_up,x_loc,y_loc);
			break;
		case ARROW_DOWN:
			draw_bitmap(&arrow_down,x_loc,y_loc);
			break;
		case ARROW_LEFT:
			draw_bitmap(&arrow_left,x_loc,y_loc);
			break;
		case ARROW_RIGHT:
			draw_bitmap(&arrow_right,x_loc,y_loc);
			break;
		case HAMSTER:
			draw_bitmap(&hamster,x_loc,y_loc);
			break;
	}


}

void draw_bitmap(bitmap_info * image,int x_loc,int y_loc)
{
	int width = image->width;
	int height = image->height;
	int i,j;

//	float x_ratio = (float)(width/VGA_DISPLAY_X);
//	float y_ratio = (float)(height/VGA_DISPLAY_Y) ;

	//Loop for X
	for(i = x_loc; i < image->width+x_loc ; i++)
	{
		//Loop for Y
		for(j = y_loc; j < image->height+y_loc; j++)
		{
			int x_location = i-x_loc;//*x_ratio;
			int y_location = j-y_loc;//*y_ratio;
			UB_VGA_SetPixel(i,j,image->ptr_bmp[(int)(x_location + y_location*width)]);
		}
	}
}
