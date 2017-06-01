#include "stm32_ub_vga_screen.h"

void rechthoek(int x_lo, int y_lo, int x_rb, int y_rb, int kleur);
void ellipse_old(int x1, int y1, int height, int width);
void ellipse_filled(int x1, int y1, int height, int width);
void ellipse(int x1, int y1, int width, int height, int color);
void line_fast(int x1, int y1, int x2, int y2, int color);
void line_fast2(int x1, int y1, int x2, int y2, int thickness, int color);

#define sgn(x) ((x<0)?-1:((x>0)?1:0)) /* macro to return the sign of a
                                         number. Bij x < 0 doet het -1. Bij x > 0 doet het 1 (positief). Anderzijds wordt het 0*/
