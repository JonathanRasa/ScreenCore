//--------------------------------------------------------------
// File     : main.c
// Datum    : 30.03.2016
// Version  : 1.0
// Autor    : UB
// mods by	: J.F. van der Bent
// CPU      : STM32F4
// IDE      : CooCox CoIDE 1.7.x
// Module   : CMSIS_BOOT, M4_CMSIS_CORE
// Function : VGA_core DMA LIB 320x240, 8bit color
//--------------------------------------------------------------

#include "main.h"




int main(void)
{
	SystemInit(); // System speed to 168MHz
	UART_init();
	UB_VGA_Screen_Init(); // Init VGA-Screen
	DELAY_init();
	UB_VGA_FillScreen(VGA_COL_BLACK);

	load_bitmap(HAMSTER,0,0);

	while(1)
	{
		api_commands();
	}
}

