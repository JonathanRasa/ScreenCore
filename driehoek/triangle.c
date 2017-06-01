#include "triangle.h"

void triangle(uint8_t x1, uint8_t y1,uint8_t x2,uint8_t y2,uint8_t x3,uint8_t y3,uint8_t color,uint8_t thickness)
{
	line_fast(x1,y1,x2,y2,color);//thickness
	line_fast(x2,y2,x3,y3,color);//thickness
	line_fast(x3,y3,x1,y1,color);//thickness
}
