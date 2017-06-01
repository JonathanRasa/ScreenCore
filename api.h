#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "stm32_ub_vga_screen.h"
#include "delay.h"
#include "main.h"
#include "includes.h"

void api_commands(void);

#define BUFSIZE		127
#define BUF2SIZE0	8
#define BUF2SIZE1	63
