#include "main.h"
#include "stm32_ub_vga_screen.h"
#include "draw_pixel.h"

/**
     * @brief Clear the screen
     * @par Implemented as
     * - clear_screen()
     */

void draw_pixel(uint8_t x, uint8_t y, uint8_t color_pixel)
{
	UB_VGA_SetPixel(x,y,color_pixel);
}
