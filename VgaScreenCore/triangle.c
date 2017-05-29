#include "main.h"
#include "stm32_ub_vga_screen.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
#include "test.h"
#include "fill.h"

//this form can not be filled in an other colour
void triangle(uint8_t x1, uint8_t y1,uint8_t x2,uint8_t y2,uint8_t x3,uint8_t y3,uint8_t color,uint8_t thickness)
{
	line_fast(x1,y1,x2,y2,color,thickness);//thickness
	line_fast(x2,y2,x3,y3,color,thickness);//thickness
	line_fast(x3,y3,x1,y1,color,thickness);//thickness

	fill( color, 1 ,  color); //creates a filled triangle

}
