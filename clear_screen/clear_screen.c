#include "main.h"
#include "stm32_ub_vga_screen.h"
#include "clear_screen.h"

/**
     * @brief Clear the screen
     * @par Implemented as
     * - clear_screen()
     */

void clear_screen(uint8_t clearscreen_color)
{
	UB_VGA_FillScreen(clearscreen_color);
}
