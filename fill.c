#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include "triangle.h"



//fills a form
void fill(uint8_t line_color, uint8_t thickness, uint8_t fill_color)
{



    //loop through every pixel column
    int x;
    for (x = 0; x < VGA_DISPLAY_X; x++ )
    {
        // Loop through every pixel row
        int y;
        for (y = 0; y < VGA_DISPLAY_Y; y++ )
        {
        	//zoekt naar een lijn
            if(UB_VGA_ReadPixel(x,y) == line_color)
            {

            	//telt dikte van lijn,bij lijn op en kijkt of daar geen lijnkleur is.
                while((UB_VGA_ReadPixel(x,y+thickness) != line_color) && (y<VGA_DISPLAY_Y)) //&& (new_loc <(VGA_DISPLAY_X*VGA_DISPLAY_Y)) && (array[new_loc] != fill_color))
                {

                    y++; // zoekt op y-positie een 2de lijnpunt

                    //wanneer een 2de lijnpunt is gevonden
                    if ((UB_VGA_ReadPixel(x,y+thickness) == line_color)&& (y<VGA_DISPLAY_Y))
                    {

                    	//bij het vinden van de eerste lijnpixel wordt -1 gedaan voor fill
                        while((UB_VGA_ReadPixel(x,y+thickness-1)!= line_color) && (y<VGA_DISPLAY_Y))
                        {

                            UB_VGA_SetPixel(x,(y+thickness),fill_color);
                            //wanneer 2de punt gevonden is wordt per ylijn de vorm gevuld
                            y--;
                            //voor het behouden van de buitenste omlijning
                            UB_VGA_SetPixel(x,(y+thickness),line_color);

                        }


                    }

                }
                //wanneer niet gelijk een zwart punt vindt, optellen
                if(UB_VGA_ReadPixel(x,y+thickness) == line_color)
                {

                    	while(UB_VGA_ReadPixel(x,y+thickness)== line_color && (y<VGA_DISPLAY_Y))
                    	{
                    		y++;
                    	}
                }




            }





        }
    }
}

